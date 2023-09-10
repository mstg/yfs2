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

#ifndef YFS2_LIBETCD_LIBETCD_H_
#define YFS2_LIBETCD_LIBETCD_H_

#include <vector>

#include "etcdv3/lease.h"

#include "third_party/etcd/api/etcdserverpb/rpc.grpc.pb.h"

namespace resf::etcdv3 {

class Client {
 public:
  explicit Client(const std::string& endpoint);
  virtual ~Client() = default;

  // Helper methods
  virtual std::optional<std::string> GetKeyValue(const std::string& key);
  virtual void PutKeyValue(const std::string& key, const std::string& value);

  // Lease helper
  virtual std::unique_ptr<resf::etcdv3::Lease> CreateLease(int ttl);
 private:
  std::shared_ptr<grpc::Channel> channel;
  std::unique_ptr<etcdserverpb::KV::Stub> kv;
};

} // namespace resf

#endif //YFS2_LIBETCD_LIBETCD_H_
