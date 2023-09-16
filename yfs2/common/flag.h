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

#ifndef YFS2_COMMON_FLAG_H_
#define YFS2_COMMON_FLAG_H_

#include "absl/flags/flag.h"

namespace yfs2::common {

#include <string>

char *__DO_NOT_USE_EnvValue(const std::string &name) {
  auto n = name;
  for (auto &c : n) c = static_cast<char>(toupper(c));
  return getenv(n.c_str());
}
#define __DO_NOT_USE_EnvValue(name) __REALLY_DO_NOT_CALL_EnvValue()

std::string __DO_NOT_USE_DefaultStringValue(const std::string &name,
                                            const std::string &default_value) {
  auto env = (yfs2::common::__DO_NOT_USE_EnvValue)(name);
  if (env != nullptr) {
    return {env};
  }
  return default_value;
}
#define __DO_NOT_USE_DefaultStringValue(name, default_value) __REALLY_DO_NOT_CALL_DefaultStringValue()

std::optional<std::string> __DO_NOT_USE_DefaultOptionalStringValue(const std::string &name,
                                                                   const std::optional<std::string> &default_value) {
  auto env = (yfs2::common::__DO_NOT_USE_EnvValue)(name);
  if (env != nullptr) {
    return {env};
  }
  return default_value;
}
#define __DO_NOT_USE_DefaultOptionalStringValue(name, default_value) __REALLY_DO_NOT_CALL_DefaultOptionalStringValue()

int32_t __DO_NOT_USE_DefaultInt32Value(const std::string &name, int32_t default_value) {
  auto env = (yfs2::common::__DO_NOT_USE_EnvValue)(name);
  if (env != nullptr) {
    return std::stoi(env);
  }
  return default_value;
}
#define __DO_NOT_USE_DefaultInt32Value(name, default_value) __REALLY_DO_NOT_CALL_DefaultInt32Value()

bool __DO_NOT_USE_DefaultBoolValue(const std::string &name, bool default_value) {
  auto env = (yfs2::common::__DO_NOT_USE_EnvValue)(name);
  if (env != nullptr) {
    return std::string(env) == "true";
  }
  return default_value;
}
#define __DO_NOT_USE_DefaultBoolValue(name, default_value) __REALLY_DO_NOT_CALL_DefaultBoolValue()

#define YFS2_STRING_FLAG(name, default_value, help) \
  ABSL_FLAG(std::string, name, (yfs2::common::__DO_NOT_USE_DefaultStringValue)("YFS2_" #name, default_value), help);

#define YFS2_OPTIONAL_STRING_FLAG(name, default_value, help) \
  ABSL_FLAG(std::optional<std::string>, name, (yfs2::common::__DO_NOT_USE_DefaultOptionalStringValue)("YFS2_" #name, default_value), help); // NOLINT

#define YFS2_INT32_FLAG(name, default_value, help) \
  ABSL_FLAG(int32_t, name, (yfs2::common::__DO_NOT_USE_DefaultInt32Value)("YFS2_" #name, default_value), help);

#define YFS2_BOOL_FLAG(name, default_value, help) \
  ABSL_FLAG(bool, name, (yfs2::common::__DO_NOT_USE_DefaultBoolValue)("YFS2_" #name, default_value), help);

}  // namespace yfs2::common

#endif  // YFS2_COMMON_FLAG_H_
