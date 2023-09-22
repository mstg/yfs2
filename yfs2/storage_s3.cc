// yfs2 (Yumrepofs2) virtual read-write-many Yum repository server
// Copyright (C) 2023 Mustafa Gezen
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include "yfs2/storage_s3.h"

#include <list>
#include <utility>

using minio::http::DataFunctionArgs;
using minio::creds::IamAwsProvider;
using std::optional;

namespace yfs2 {

StorageS3::StorageS3(std::string bucket_,
                     bool debug,
                     optional<std::string> region_,
                     const optional<std::string>& access_key,
                     const optional<std::string>& secret_key,
                     const std::string& endpoint,
                     bool endpoint_secure) {
  bucket = std::move(bucket_);
  url = std::make_shared<minio::s3::BaseUrl>(endpoint);
  url->https = endpoint_secure;

  // If keys are not manually provided, use AWS IAM
  if (!access_key || !secret_key) {
    // Set the AWS_REGION environment variable if region is set
    if (region_) {
      setenv("AWS_REGION", region_->c_str(), 1);
    }

    // If region is not set, and AWS_REGION is not set, then
    // set the default region to us-east-2. We must have a region
    // set for IAM to work.
    if (!region_ && !getenv("AWS_REGION")) {
      setenv("AWS_REGION", "us-east-2", 1);
    }
    creds = std::make_shared<IamAwsProvider>();
  } else {
    // Default back to static credentials, and if one of the keys
    // are null then set them to empty strings.
    // We'll deal with failures later.
    auto access_key_id_ = access_key.value_or("");
    auto secret_access_key_ = secret_key.value_or("");

    using StaticProvider = minio::creds::StaticProvider;
    creds = std::make_shared<StaticProvider>(access_key_id_,
                                                   secret_access_key_);
  }

  client = std::make_shared<minio::s3::Client>(*url,
                                               &*creds);
  client->Debug(debug);
  region = region_.value_or("us-east-2");
}

absl::Status StorageS3::Download(const std::string &path,
                                 const std::string &dest_path) {
  minio::s3::DownloadObjectArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;
  args.filename = dest_path;

  auto res = client->DownloadObject(args);
  if (res) {
    return absl::OkStatus();
  }

  if (res.Error().String().find("NoSuchKey") != std::string::npos) {
    return absl::NotFoundError("object not found");
  }

  if (res.Error().String().find("already exists") != std::string::npos) {
    return absl::AlreadyExistsError("file already exists");
  }

  return absl::InternalError(res.Error().String());
}

absl::StatusOr<std::string> StorageS3::Get(const std::string &path) {
  minio::s3::GetObjectArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;

  std::string content;
  args.datafunc = [&content = content](const DataFunctionArgs &args) -> bool {
    content.insert(content.end(), args.datachunk.begin(), args.datachunk.end());
    return true;
  };

  auto res = client->GetObject(args);
  if (res) {
    return content;
  }

  if (res.Error().String().find("NoSuchKey") != std::string::npos) {
    return absl::NotFoundError("object not found");
  }

  return absl::InternalError(res.Error().String());
}

absl::StatusOr<std::string> StorageS3::StartMultipartUpload(const std::string &path) {
  minio::s3::CreateMultipartUploadArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;
  auto res = client->CreateMultipartUpload(args);
  if (res) {
    return res.upload_id;
  }

  return absl::InternalError(res.Error().String());
}

absl::StatusOr<StoragePart> StorageS3::UploadPart(const std::string &path,
                                                  const std::string &upload_id,
                                                  const uint32_t &part_number,
                                                  const std::string &content) {
  minio::s3::UploadPartArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;
  args.upload_id = upload_id;
  args.part_number = part_number;
  args.data = content;
  auto res = client->UploadPart(args);
  if (res) {
    StoragePart part(part_number, res.etag);
    return part;
  }

  return absl::InternalError(res.Error().String());
}

absl::Status StorageS3::CompleteMultipartUpload(const std::string &path,
                                                const std::string &upload_id,
                                                const std::vector<StoragePart> &parts) {
  minio::s3::CompleteMultipartUploadArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;
  args.upload_id = upload_id;

  std::list<minio::s3::Part> minio_parts;
  for (const auto &part : parts) {
    minio::s3::Part minio_part;
    minio_part.number = part.number;
    minio_part.etag = part.etag;
    minio_parts.push_back(minio_part);
  }

  args.parts = minio_parts;

  auto res = client->CompleteMultipartUpload(args);
  if (res) {
    return absl::OkStatus();
  }

  return absl::InternalError(res.Error().String());
}

}  // namespace yfs2
