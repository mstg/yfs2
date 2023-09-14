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

#include "yfs2/rpm.h"

#include <fcntl.h>

#include <rpm/rpmts.h>

namespace yfs2 {

Rpm::Rpm(bool ignore_signature) {
  ts = rpmtsCreate();

  rpmVSFlags vs_flags = 0;
  if (ignore_signature) {
    vs_flags |= RPMVSF_MASK_NOSIGNATURES;
  }

  rpmtsSetVSFlags(ts, vs_flags);
}

Rpm::~Rpm() {
  // librpm is a C library, so we have to free the resources manually
  // Free header if it is not null
  if (header != nullptr) {
    headerFree(header);
  }

  // If file descriptor is not null, close it
  if (fd != nullptr) {
    Fclose(fd);
  }

  // Transaction set is always created, so we have to free it
  rpmtsFree(ts);
}

absl::Status Rpm::Init(const std::string &rpm_path) {
  // Open the file
  fd = Fopen(rpm_path.c_str(), "r");

  // Check error
  int fe = Ferror(fd);
  if (fe == ENOENT) {
    return absl::NotFoundError("file not found");
  } else if (fe != 0) {
    return absl::InternalError("unknown error");
  }

  // Open the rpm
  rpmRC read_rc = rpmReadPackageFile(ts, fd, rpm_path.c_str(), &header);
  switch (read_rc) {
    case RPMRC_OK:break;
    case RPMRC_NOTFOUND:return absl::InvalidArgumentError("header not found");
    case RPMRC_NOTTRUSTED:return absl::InvalidArgumentError("not trusted");
    case RPMRC_NOKEY:return absl::InvalidArgumentError("no key");
    default:return absl::InternalError("unknown error");
  }

  return absl::OkStatus();
}

absl::StatusOr<std::string> Rpm::GetHeaderStr(const rpmTagVal &tag) {
  // Get the header
  const char *header_value_c = headerGetString(header, tag);
  if (header_value_c == nullptr) {
    return absl::NotFoundError("header not found");
  }

  return std::string(header_value_c);
}

}  // namespace yfs2
