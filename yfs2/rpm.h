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

#ifndef YFS2_RPM_H_
#define YFS2_RPM_H_

#include <string>
#include <utility>

#include "rpm/rpmlib.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace yfs2 {

class Rpm {
 public:
  explicit Rpm(bool ignore_signature = false);
  virtual ~Rpm();

  virtual absl::Status Init(const std::string &rpm_path);
  virtual absl::Status InitWithHeaderOnly(void *header_data);

  virtual absl::StatusOr<std::pair<void*, uint32_t>> ExportHeader();

  virtual absl::StatusOr<std::string> GetHeaderStr(const rpmTagVal &tag);

 private:
  rpmts ts;
  FD_t fd = nullptr;
  Header header = nullptr;
};

}  // namespace yfs2

#endif  // YFS2_RPM_H_
