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

#include <grpcpp/grpcpp.h>

#include <utility>

#include "yfs2/etcdv3_lease.h"

namespace yfs2 {

EtcdLease::EtcdLease(std::shared_ptr<grpc::Channel> channel, int ttl) {
  active = true;

  this->channel = std::move(channel);
  lease = etcdserverpb::Lease::NewStub(this->channel);

  // Create lease
  auto req = etcdserverpb::LeaseGrantRequest();
  req.set_ttl(ttl);
  etcdserverpb::LeaseGrantResponse resp;
  grpc::ClientContext ctx;
  lease->LeaseGrant(&ctx, req, &resp);

  lease_id = resp.id();

  // Start keepalive thread
  keepalive_thread = std::thread([this]() {
    // LeaseKeepAlive is a bidirectional streaming method
    // We can use it to keep the lease alive
    grpc::ClientContext ctx;
    auto stream = lease->LeaseKeepAlive(&ctx);

    while (active) {
      // Send keepalive request
      auto req = etcdserverpb::LeaseKeepAliveRequest();
      req.set_id(lease_id);
      etcdserverpb::LeaseKeepAliveResponse resp;
      stream->Write(req);
      stream->Read(&resp);

      // Sleep for TTL - 2 seconds (min 1 second)
      int ttl = static_cast<int>(resp.ttl());
      int sleep_time = std::max(1, ttl - 2);
      std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    }

    // Close stream
    stream->WritesDone();
    stream->Finish();
  });
}

void EtcdLease::Close() {
  // Cancel keepalive thread
  active = false;
  keepalive_thread.join();

  // Revoke lease
  grpc::ClientContext ctx;
  auto req = etcdserverpb::LeaseRevokeRequest();
  req.set_id(lease_id);
  etcdserverpb::LeaseRevokeResponse resp;
  lease->LeaseRevoke(&ctx, req, &resp);
}

}

