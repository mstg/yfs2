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

#include <glog/logging.h>
#include "absl/cleanup/cleanup.h"

#include "yfs2/rpm.h"
#include "yfs2/mutation_server/impl.h"
#include "yfs2/storage_s3.h"

namespace yfs2::mutation_server {

MutationServerImpl::MutationServerImpl() {
  etcd = std::make_shared<yfs2::EtcdClient>("localhost:2379");

  auto val = etcd->GetKeyValue("test2");
  if (val) {
    LOG(INFO) << "test: " << *val << "\n";
  } else {
    LOG(ERROR) << "test: not found" << "\n";
  }

  auto rpm = std::make_unique<yfs2::Rpm>(true);
  auto err = rpm->Init("/tmp/nginx-1.14.1-9.module+el8.0.0+4108+af250afe.src.rpm");
  if (err != yfs2::RPM_OK) {
    LOG(ERROR) << yfs2::RpmErrorToString(err) << "\n";
  }

  std::string name;
  err = rpm->GetHeaderStr(5096, &name);
  if (err != yfs2::RPM_OK) {
    LOG(ERROR) << yfs2::RpmErrorToString(err) << "\n";
  }

  LOG(INFO) << "name: " << name << "\n";

  auto storage = std::make_shared<yfs2::StorageS3>();
  auto s_err = storage->Download("nano-2.9.8-1.el8.src.rpm", "/tmp/nano-2.9.8-1.el8.src.rpm");
  if (s_err != yfs2::STORAGE_OK) {
    LOG(ERROR) << "storage error: " << s_err << "\n";
  }
}

grpc::Status MutationServerImpl::Hello(grpc::ServerContext *context,
                                       const yumrepofs::v2::HelloRequest *request,
                                       yumrepofs::v2::HelloResponse *response) {
  etcd->PutKeyValue("test2", request->name());
  response->set_message("Hello, " + request->name() + "!");

  return grpc::Status::OK;
}

}
