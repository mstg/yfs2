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
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#include <glog/logging.h>

#include <client.h>

#include "storage_s3.h"

namespace yfs2 {

StorageS3::StorageS3() {
  bucket = "mship";
  region = "us-east-1";
  base_url = "localhost:9100";
  access_key_id = "minioadmin";
  secret_access_key = "minioadmin";
}

storage_errno_t StorageS3::Download(const std::string &path, const std::string &dest_path) {
  minio::s3::BaseUrl url(base_url);
  minio::creds::StaticProvider creds(access_key_id, secret_access_key);
  minio::s3::Client client(url, &creds);

  minio::s3::DownloadObjectArgs args;
  args.bucket = bucket;
  args.region = region;
  args.object = path;
  args.filename = dest_path;

  LOG(INFO) << "Downloading " << path << " to " << dest_path << "...\n";

  auto res = client.DownloadObject(args);
  if (res) {
    return STORAGE_OK;
  }

  LOG(ERROR) << "storage download error: " << res.Error().String();

  if (res.Error().String().find("404") != std::string::npos) {
    return STORAGE_OBJ_NOT_FOUND;
  }

  return STORAGE_ERROR;
}

}
