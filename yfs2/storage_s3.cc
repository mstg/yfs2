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

namespace yfs2 {

StorageS3::StorageS3() {
  bucket = "mship";
  region = "us-east-1";
  auto base_url = "localhost:9100";
  auto access_key_id = "minioadmin";
  auto secret_access_key = "minioadmin";

  url = new minio::s3::BaseUrl(base_url);
  url->https = false;

  creds = new minio::creds::StaticProvider(access_key_id, secret_access_key);
  client = std::make_shared<minio::s3::Client>(*url, creds);
  client->Debug(true);
}

StorageS3::~StorageS3() {
  delete creds;
  delete url;
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

  return absl::UnknownError("unknown error");
}

absl::StatusOr<std::string> StorageS3::Get(const std::string &path) {
  minio::s3::GetObjectArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;

  std::string content;
  using DataFunctionArgs = const minio::http::DataFunctionArgs;
  args.datafunc = [&content = content](DataFunctionArgs &args) -> bool {
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

  return absl::UnknownError("unknown error");
}

}  // namespace yfs2
