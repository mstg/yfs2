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

#ifndef YFS2_STORAGE_MINIO_H_
#define YFS2_STORAGE_MINIO_H_

#include "yfs2/storage.h"

namespace yfs2 {

class StorageS3 : public Storage {
 public:
  StorageS3();
  virtual ~StorageS3() = default;

  // Download a file from storage to a specified path.
  storage_errno_t Download(const std::string &path, const std::string &dest_path) override;
 private:
  std::string base_url;
  std::string region;
  std::string bucket;
  std::string access_key_id;
  std::string secret_access_key;
};

}

#endif
