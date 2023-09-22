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

#include "yfs2/common/status_converter.h"

namespace yfs2 {

std::string get_prefix(const std::vector<uint8_t> &key) {
  std::vector<uint8_t> end = key;

  for (u_char i = end.size() - 1; i >= 0; --i) {
    if (end[i] < 0xff) {
      end[i] = end[i] + 1;
      end.resize(i + 1);
      return {end.begin(), end.end()};
    }
  }

  // next prefix does not exist (e.g., 0xffff);
  return {};
}

EtcdClient::EtcdClient(const std::string &endpoint) {
  // Create clients
  // First a channel, then stubs
  channel = grpc::CreateChannel(endpoint, grpc::InsecureChannelCredentials());

  kv = etcdserverpb::KV::NewStub(channel);
}

absl::StatusOr<std::string> EtcdClient::GetKeyValue(const std::string &key) {
  auto req = etcdserverpb::RangeRequest();
  req.set_key(key);
  etcdserverpb::RangeResponse resp;
  grpc::ClientContext ctx;

  auto status = kv->Range(&ctx, req, &resp);
  if (!status.ok()) {
    return yfs2::common::StatusConverter::Convert(status);
  }

  if (resp.kvs_size() == 0) {
    return absl::NotFoundError("key not found");
  }

  return resp.kvs(0).value();
}

absl::StatusOr<std::vector<std::string>> EtcdClient::GetKeyValuesWithPrefix(const std::string &prefix) {
  // Convert prefix to bytes (uint8_t array)
  std::vector<uint8_t> prefix_bytes(prefix.begin(), prefix.end());

  auto req = etcdserverpb::RangeRequest();
  auto prefix_range_end = get_prefix(prefix_bytes);
  req.set_range_end(prefix_range_end);
  req.set_key(prefix);
  etcdserverpb::RangeResponse resp;
  grpc::ClientContext ctx;

  auto status = kv->Range(&ctx, req, &resp);
  if (!status.ok()) {
    return yfs2::common::StatusConverter::Convert(status);
  }

  std::vector<std::string> values;
  values.reserve(resp.kvs_size());
  for (int i = 0; i < resp.kvs_size(); ++i) {
    values.push_back(resp.kvs(i).value());
  }

  return values;
}

absl::Status EtcdClient::PutKeyValue(const std::string &key,
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

  auto res = kv->Put(&ctx, req, &resp);

  return yfs2::common::StatusConverter::Convert(res);
}

absl::Status EtcdClient::RemoveLeaseFromKey(const std::string &key) {
  auto req = etcdserverpb::PutRequest();
  req.set_key(key);
  req.set_ignore_value(true);

  etcdserverpb::PutResponse resp;
  grpc::ClientContext ctx;

  auto res = kv->Put(&ctx, req, &resp);

  return yfs2::common::StatusConverter::Convert(res);
}

std::shared_ptr<EtcdLock> EtcdClient::CreateLock() {
  return std::make_shared<yfs2::EtcdLock>(channel);
}

std::shared_ptr<yfs2::EtcdLease> EtcdClient::CreateLease(int ttl) {
  return std::make_shared<yfs2::EtcdLease>(channel, ttl);
}

}  // namespace yfs2
