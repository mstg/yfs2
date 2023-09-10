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

#ifndef YFS2_MUTATION_SERVER_IMPL_H_
#define YFS2_MUTATION_SERVER_IMPL_H_

#include "yfs2/etcdv3.h"
#include "yumrepofs/v2/mutation_server.grpc.pb.h"

namespace yfs2::mutation_server {

class MutationServerImpl : public yumrepofs::v2::MutationServer::Service {
 public:
  MutationServerImpl();

  grpc::Status Hello(grpc::ServerContext *context,
                     const yumrepofs::v2::HelloRequest *request,
                     yumrepofs::v2::HelloResponse *response) override;
 private:
  std::shared_ptr<yfs2::EtcdClient> etcd;
};

}

#endif
