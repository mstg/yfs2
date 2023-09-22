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

#include "yfs2/refilling_cache.h"

namespace yfs2 {

RefillingCache::RefillingCache(std::shared_ptr<EtcdClient> _etcd,
                               std::shared_ptr<Storage> _storage,
                               bool _ignore_signatures) {
  etcd = std::move(_etcd);
  storage = std::move(_storage);
  ignore_signatures = _ignore_signatures;
}

absl::StatusOr<tuple<std::string, Rpm>> RefillingCache::GetRpm(const std::string &rpm_path) {
  std::lock_guard<std::mutex> lock(cache_mutex);

  // Check if we have it in cache
  auto cached = header_cache.find(rpm_path);

  // Found in cache, return it
  if (cached != header_cache.end()) {
    // Get hash from cache
    auto hash_cached = hash_cache.find(rpm_path);
    if (hash_cached != hash_cache.end()) {
      return std::make_tuple(hash_cached->second, cached->second);
    }

    // If hash is not in cache, refetch from etcd
    header_cache.erase(cached);
  }

  // Not found in cache, fetch from etcd
  auto status = etcd->GetKeyValue(rpm_path);
  if (!status.ok()) {
    if (status.status().code() == absl::StatusCode::kNotFound) {
      return absl::NotFoundError("RPM not found in etcd");
    }
    // Since we can't convert grpc::Status to absl::Status, this is the easiest way
    return absl::InternalError(status.status().message());
  }
  auto hash = status.value();

  // Get RPM header from storage
  auto rpm_data = storage->Get(rpm_path + ".header");
  if (!rpm_data.ok()) {
    if (rpm_data.status().code() == absl::StatusCode::kNotFound) {
      return absl::NotFoundError("RPM header not found in storage");
    }
    return absl::InternalError(rpm_data.status().message());
  }

  auto rpm = Rpm(ignore_signatures);
  auto err = rpm.InitWithHeaderOnly(const_cast<char *>(rpm_data.value().c_str()));
  if (!err.ok()) {
    return absl::InternalError(err.message());
  }

  header_cache[rpm_path] = rpm;
  hash_cache[rpm_path] = hash;

  return std::make_tuple(hash, rpm);
}

absl::StatusOr<ModuleStream> RefillingCache::GetModuleStream(const std::string &module_name,
                                                             const std::string &stream_name,
                                                             const std::string &context) {
  std::lock_guard<std::mutex> lock(module_mutex);

  // Check if we have it in cache
  auto module_key = module_name + "-" + stream_name + "-" + context;
  auto cached = module_cache.find(module_key);
  if (cached != module_cache.end()) {
    module_mutex.unlock();
    return cached->second;
  }

  // Not found in cache, fetch from etcd
  auto etcd_key = "/yfs2/" + module_key;
  auto status = etcd->GetKeyValue(etcd_key);
  if (!status.ok()) {
    if (status.status().code() == absl::StatusCode::kNotFound) {
      return absl::NotFoundError("module stream not found in etcd");
    }

    return status.status();
  }

  auto module_stream = ModuleStream();
  if (!module_stream.ParseFromString(status.value())) {
    return absl::InternalError("failed to parse module stream");
  }
  return module_stream;
}

}  // namespace yfs2
