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

#ifndef YFS2_STORAGE_H_
#define YFS2_STORAGE_H_

#include <cstdint>
#include <string>

#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace yfs2 {

class Storage {
 public:
  // Download a file from storage to a specified path.
  virtual absl::Status Download(const std::string &path,
                                const std::string &dest_path) {
    return absl::UnimplementedError("unimplemented");
  }

  // Upload a file from a specified path to storage.
  virtual absl::Status Upload(const std::string &path,
                              const std::string &dest_path) {
    return absl::UnimplementedError("unimplemented");
  }

  // Exists checks if a file exists in storage.
  virtual absl::StatusOr<bool> Exists(const std::string &path) {
    return absl::UnimplementedError("unimplemented");
  }

  // Get a file's content directly from storage.
  virtual absl::StatusOr<std::string> Get(const std::string &path) {
    return absl::UnimplementedError("unimplemented");
  }
};

}  // namespace yfs2

#endif  // YFS2_STORAGE_H_
