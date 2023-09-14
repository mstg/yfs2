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

#include "yfs2/etcdv3_lock.h"

#include <utility>

#include "grpcpp/grpcpp.h"

namespace yfs2 {

EtcdLock::EtcdLock(std::shared_ptr<grpc::Channel> channel) {
  this->channel = std::move(channel);
  this->lock = v3lockpb::Lock::NewStub(this->channel);
}

grpc::Status EtcdLock::Lock(const std::string &name, const int64_t &lease_id) {
  grpc::ClientContext context;
  v3lockpb::LockRequest request;
  v3lockpb::LockResponse response;
  request.set_name(name);
  request.set_lease(lease_id);
  grpc::Status status = this->lock->Lock(&context, request, &response);
  if (!status.ok()) {
    return status;
  }
  this->key = response.key();

  return status;
}

grpc::Status EtcdLock::Unlock() {
  grpc::ClientContext context;
  v3lockpb::UnlockRequest request;
  v3lockpb::UnlockResponse response;
  request.set_key(this->key);

  return this->lock->Unlock(&context, request, &response);
}

}  // namespace yfs2
