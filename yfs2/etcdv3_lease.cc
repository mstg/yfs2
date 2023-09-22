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

#include "yfs2/etcdv3_lease.h"

#include <utility>
#include <memory>
#include <algorithm>

#include "grpcpp/grpcpp.h"

#include "yfs2/common/status_converter.h"

namespace yfs2 {

EtcdLease::EtcdLease(std::shared_ptr<grpc::Channel> channel, int ttl) {
  this->channel = std::move(channel);
  this->ttl = ttl;
  this->active = true;

  lease = etcdserverpb::Lease::NewStub(this->channel);
}

absl::Status EtcdLease::Start() {
  // Create lease
  auto req = etcdserverpb::LeaseGrantRequest();
  req.set_ttl(ttl);
  etcdserverpb::LeaseGrantResponse resp;
  grpc::ClientContext ctx;
  auto status = lease->LeaseGrant(&ctx, req, &resp);
  if (!status.ok()) {
    return yfs2::common::StatusConverter::Convert(status);
  }

  lease_id = resp.id();

  // Start keepalive thread
  keepalive_thread = std::thread([this]() {
    // LeaseKeepAlive is a bidirectional streaming method
    // We can use it to keep the lease alive
    grpc::ClientContext ctx2;
    auto stream = lease->LeaseKeepAlive(&ctx2);
    if (!stream) {
      keepalive_status = absl::InternalError("failed to create LeaseKeepAlive stream");
      return;
    }

    while (active) {
      // Send keepalive request
      auto req = etcdserverpb::LeaseKeepAliveRequest();
      req.set_id(lease_id);
      etcdserverpb::LeaseKeepAliveResponse resp;
      stream->Write(req);
      if (!stream->Read(&resp)) {
        keepalive_status = absl::InternalError("failed to read LeaseKeepAlive response");
        return;
      }

      // Sleep for TTL - 2 seconds (min 1 second)
      int sleep_ttl = static_cast<int>(resp.ttl());
      int sleep_time = std::max(1, sleep_ttl - 2);
      std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    }

    // Close stream
    stream->WritesDone();
    keepalive_status = yfs2::common::StatusConverter::Convert(stream->Finish());
  });

  return absl::OkStatus();
}

int64_t EtcdLease::GetLeaseId() {
  return lease_id;
}

absl::Status EtcdLease::Close() {
  if (lease_id == 0) {
    return absl::InternalError("lease_id is 0");
  }

  // Cancel keepalive thread
  active = false;
  keepalive_thread.join();
  if (!keepalive_status.ok()) {
    return keepalive_status;
  }

  // Revoke lease
  grpc::ClientContext ctx;
  auto req = etcdserverpb::LeaseRevokeRequest();
  req.set_id(lease_id);
  etcdserverpb::LeaseRevokeResponse resp;
  auto res = lease->LeaseRevoke(&ctx, req, &resp);

  return yfs2::common::StatusConverter::Convert(res);
}

absl::Status EtcdLease::Close(const std::shared_ptr<grpc::Channel>& channel, int64_t lease_id) {
  auto lease = etcdserverpb::Lease::NewStub(channel);

  grpc::ClientContext ctx;
  auto req = etcdserverpb::LeaseRevokeRequest();
  req.set_id(lease_id);
  etcdserverpb::LeaseRevokeResponse resp;
  auto res = lease->LeaseRevoke(&ctx, req, &resp);

  return yfs2::common::StatusConverter::Convert(res);
}

}  // namespace yfs2

