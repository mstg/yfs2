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

#ifndef YFS2_STORAGE_S3_H_
#define YFS2_STORAGE_S3_H_

#include <memory>
#include <string>

#include "minio/client.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"

#include "yfs2/storage.h"

namespace yfs2 {

class StorageS3 : public Storage {
 public:
  StorageS3();
  virtual ~StorageS3();

  // Download a file from storage to a specified path.
  absl::Status Download(const std::string &path,
                        const std::string &dest_path) override;

  // Get a file's content directly from storage.
  absl::StatusOr<std::string> Get(const std::string &path) override;
 private:
  std::string region;
  std::string bucket;
  std::shared_ptr<minio::s3::Client> client;
  // minio client uses raw pointers for some reason?
  minio::creds::StaticProvider *creds;
  minio::s3::BaseUrl *url;
};

}  // namespace yfs2

#endif  // YFS2_STORAGE_S3_H_
