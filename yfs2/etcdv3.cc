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

#include "yfs2/etcdv3.h"

#include <memory>
#include <string>

#include "grpcpp/grpcpp.h"

namespace yfs2 {

EtcdClient::EtcdClient(const std::string &endpoint) {
  // Create clients
  // First a channel, then stubs
  channel = grpc::CreateChannel(endpoint, grpc::InsecureChannelCredentials());

  kv = etcdserverpb::KV::NewStub(channel);
}

grpc::Status EtcdClient::GetKeyValue(const std::string &key,
                                     std::optional<std::string> *value) {
  auto req = etcdserverpb::RangeRequest();
  req.set_key(key);
  etcdserverpb::RangeResponse resp;
  grpc::ClientContext ctx;

  auto status = kv->Range(&ctx, req, &resp);
  if (!status.ok()) {
    return status;
  }

  if (resp.kvs_size() == 0) {
    *value = std::nullopt;
  } else {
    *value = resp.kvs(0).value();
  }

  return status;
}

grpc::Status EtcdClient::PutKeyValue(const std::string &key,
                                     const std::string &value,
                                     const std::optional<int64_t> &lease_id) {
  auto req = etcdserverpb::PutRequest();
  req.set_key(key);
  req.set_value(value);

  if (lease_id.has_value()) {
    req.set_lease(lease_id.value());
  }

  etcdserverpb::PutResponse resp;
  grpc::ClientContext ctx;

  return kv->Put(&ctx, req, &resp);
}

grpc::Status EtcdClient::RemoveLeaseFromKey(const std::string &key) {
  auto req = etcdserverpb::PutRequest();
  req.set_key(key);
  req.set_ignore_value(true);

  etcdserverpb::PutResponse resp;
  grpc::ClientContext ctx;

  return kv->Put(&ctx, req, &resp);
}

std::shared_ptr<EtcdLock> EtcdClient::CreateLock() {
  return std::make_shared<yfs2::EtcdLock>(channel);
}

std::shared_ptr<yfs2::EtcdLease> EtcdClient::CreateLease(int ttl) {
  return std::make_shared<yfs2::EtcdLease>(channel, ttl);
}

}  // namespace yfs2
