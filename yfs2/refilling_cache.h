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

#ifndef YFS2_REFILLING_CACHE_H_
#define YFS2_REFILLING_CACHE_H_

#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <utility>

#include "absl/status/status.h"
#include "absl/status/statusor.h"

#include "yumrepofs/v2/module.pb.h"

#include "yfs2/etcdv3.h"
#include "yfs2/rpm.h"
#include "yfs2/storage.h"

using std::tuple;
using yumrepofs::v2::ModuleStream;

namespace yfs2 {

class RefillingCache {
 public:
  explicit RefillingCache(std::shared_ptr<EtcdClient> _etcd,
                          std::shared_ptr<Storage> _storage,
                          bool _ignore_signatures);
  virtual ~RefillingCache() = default;

  // GetRpm returns the SHA256 of the whole RPM file and the RPM object (only headers)
  virtual absl::StatusOr<tuple<std::string, Rpm>> GetRpm(const std::string &rpm_path);
  virtual absl::StatusOr<ModuleStream> GetModuleStream(const std::string &module_name,
                                                       const std::string &stream_name,
                                                       const std::string &context);

 private:
  std::shared_ptr<EtcdClient> etcd;
  std::shared_ptr<Storage> storage;
  bool ignore_signatures = false;

  std::map<std::string, Rpm> header_cache;
  std::map<std::string, std::string> hash_cache;
  std::map<std::string, ModuleStream> module_cache;
  std::mutex cache_mutex;
  std::mutex module_mutex;
};

}  // namespace yfs2

#endif  // YFS2_REFILLING_CACHE_H_
