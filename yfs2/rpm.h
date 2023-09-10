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

#ifndef YFS2_RPM_H_
#define YFS2_RPM_H_

#include <string>
#include <rpm/rpmlib.h>

namespace yfs2 {

typedef int32_t rpm_errno_t;
static const rpm_errno_t RPM_OK = 0;
static const rpm_errno_t RPM_FILE_NOT_FOUND = -1;
static const rpm_errno_t RPM_ERROR = -2;
static const rpm_errno_t RPM_HEADER_NOT_FOUND = -3;
static const rpm_errno_t RPM_NOT_TRUSTED = -4;
static const rpm_errno_t RPM_NO_KEY = -5;

std::string RpmErrorToString(rpm_errno_t error);

class Rpm {
 public:
  explicit Rpm(bool ignore_signature = false);
  virtual ~Rpm();

  virtual rpm_errno_t Init(const std::string &rpm_path);
  virtual rpm_errno_t GetHeaderStr(const rpmTagVal &tag, std::string *header_value);
 private:
  rpmts ts;
  FD_t fd;
  Header header;
};

}

#endif
