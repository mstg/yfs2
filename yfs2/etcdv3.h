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

#ifndef YFS2_ETCDV3_H_
#define YFS2_ETCDV3_H_

#include <memory>
#include <string>
#include <vector>

#include "third_party/etcd/api/etcdserverpb/rpc.grpc.pb.h"
#include "yfs2/etcdv3_lease.h"
#include "yfs2/etcdv3_lock.h"

namespace yfs2 {

class EtcdClient {
 public:
  explicit EtcdClient(const std::string &endpoint);
  virtual ~EtcdClient() = default;

  // Helper methods
  virtual grpc::Status GetKeyValue(
      const std::string &key,
      std::optional<std::string> *value);
  virtual grpc::Status PutKeyValue(
      const std::string &key,
      const std::string &value,
      const std::optional<int64_t> &lease_id);

  // Lock helper
  virtual std::shared_ptr<EtcdLock> CreateLock();

  // Lease helper
  virtual std::shared_ptr<EtcdLease> CreateLease(int ttl);
 private:
  std::shared_ptr<grpc::Channel> channel;
  std::unique_ptr<etcdserverpb::KV::Stub> kv;
};

}  // namespace yfs2

#endif  // YFS2_ETCDV3_H_
