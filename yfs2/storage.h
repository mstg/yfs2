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

#ifndef YFS2_STORAGE_H_
#define YFS2_STORAGE_H_

#include <cstdint>
#include <string>

namespace yfs2 {

typedef int32_t storage_errno_t;
static const storage_errno_t STORAGE_OK = 0;
static const storage_errno_t STORAGE_OBJ_NOT_FOUND = -1;
static const storage_errno_t STORAGE_ERROR = -2;

class Storage {
 public:
  // Download a file from storage to a specified path.
  virtual storage_errno_t Download(const std::string &path, const std::string &dest_path) {
    return STORAGE_ERROR;
  };

  // // Upload a file from a specified path to storage.
  // virtual storage_errno_t Upload(const std::string &path, const std::string &dest_path) = 0;

  // // Exists checks if a file exists in storage.
  // virtual storage_errno_t Exists(const std::string &path) = 0;
};

}

#endif
