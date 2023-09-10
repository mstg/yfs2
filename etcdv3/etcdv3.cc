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

#include "etcdv3/etcdv3.h"

#include <grpcpp/grpcpp.h>

namespace resf::etcdv3 {

Client::Client(const std::string& endpoint) {
  // Create clients
  // First a channel, then stubs
  channel = grpc::CreateChannel(endpoint, grpc::InsecureChannelCredentials());

  kv = etcdserverpb::KV::NewStub(channel);
}

std::optional<std::string> Client::GetKeyValue(const std::string& key) {
  auto req = etcdserverpb::RangeRequest();
  req.mutable_key()->assign(key);
  etcdserverpb::RangeResponse resp;
  grpc::ClientContext ctx;
  kv->Range(&ctx, req, &resp);

  if (resp.kvs_size() == 0) {
    return std::nullopt;
  }

  return resp.kvs(0).value();
}

void Client::PutKeyValue(const std::string& key, const std::string& value) {
  auto req = etcdserverpb::PutRequest();
  req.mutable_key()->assign(key);
  req.mutable_value()->assign(value);
  etcdserverpb::PutResponse resp;
  grpc::ClientContext ctx;
  kv->Put(&ctx, req, &resp);
}

std::unique_ptr<resf::etcdv3::Lease> Client::CreateLease(int ttl) {
  return std::make_unique<resf::etcdv3::Lease>(channel, ttl);
}

} // namespace resf
