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

#ifndef YFS2_ETCDV3_LEASE_H_
#define YFS2_ETCDV3_LEASE_H_

#include <memory>
#include <thread>

#include "third_party/etcd/api/etcdserverpb/rpc.grpc.pb.h"

namespace yfs2 {

class EtcdLease {
 public:
  explicit EtcdLease(std::shared_ptr<grpc::Channel> channel, int ttl);
  virtual ~EtcdLease() = default;
  virtual grpc::Status Start();
  virtual int64_t GetLeaseId();
  virtual grpc::Status Close();
 private:
  std::shared_ptr<grpc::Channel> channel;
  std::unique_ptr<etcdserverpb::Lease::Stub> lease;
  int ttl;
  int64_t lease_id = 0;
  std::thread keepalive_thread;
  grpc::Status keepalive_status = grpc::Status::OK;
  bool active;
};

}  // namespace yfs2

#endif  // YFS2_ETCDV3_LEASE_H_
