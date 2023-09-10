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

#include <fcntl.h>

#include <rpm/rpmts.h>

#include "yfs2/rpm.h"

namespace yfs2 {

std::string RpmErrorToString(rpm_errno_t error) {
  switch (error) {
    case RPM_OK:return "Success";
    case RPM_FILE_NOT_FOUND:return "File not found";
    case RPM_ERROR:return "Error";
    case RPM_HEADER_NOT_FOUND:return "Header not found";
    case RPM_NOT_TRUSTED:return "Not trusted";
    case RPM_NO_KEY:return "No key";
    default:return "Unknown error";
  }
}

Rpm::Rpm(bool ignore_signature) {
  fd = nullptr;
  header = nullptr;

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

rpm_errno_t Rpm::Init(const std::string &rpm_path) {
  // Open the file
  fd = Fopen(rpm_path.c_str(), "r");

  // Check error
  int fe = Ferror(fd);
  if (fe == ENOENT) {
    return RPM_FILE_NOT_FOUND;
  } else if (fe != 0) {
    return RPM_ERROR;
  }

  // Open the rpm
  rpmRC read_rc = rpmReadPackageFile(ts, fd, rpm_path.c_str(), &header);
  switch (read_rc) {
    case RPMRC_OK:break;
    case RPMRC_NOTFOUND:return RPM_HEADER_NOT_FOUND;
    case RPMRC_NOTTRUSTED:return RPM_NOT_TRUSTED;
    case RPMRC_NOKEY:return RPM_NO_KEY;
    default:return RPM_ERROR;
  }

  return RPM_OK;
}

rpm_errno_t Rpm::GetHeaderStr(const rpmTagVal &tag, std::string *header_value) {
  // Get the header
  const char *header_value_c = headerGetString(header, tag);
  if (header_value_c == nullptr) {
    return RPM_HEADER_NOT_FOUND;
  }

  // Copy the header
  *header_value = header_value_c;

  return RPM_OK;
}

}
