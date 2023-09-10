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

#include "rpm_helper/rpm.h"
#include "mutation_server/mutation_server_impl.h"

namespace resf::yumrepofs {

MutationServerImpl::MutationServerImpl() {
  etcd = std::make_unique<resf::etcdv3::Client>("localhost:2379");

  auto val = etcd->GetKeyValue("test2");
  if (val) {
    std::cout << "test: " << *val << "\n";
  } else {
    std::cout << "test: not found" << "\n";
  }

  std::unique_ptr<rpm_helper::Rpm> rpm = std::make_unique<rpm_helper::Rpm>();
  rpm_helper::rpm_errno_t err = rpm->Init("/tmp/nginx-1.14.1-9.module+el8.0.0+4108+af250afe.src.rpm");
  if (err != rpm_helper::RPM_SUCCESS) {
    std::cout << rpm_helper::ErrorToString(err) << "\n";
  }

  std::string name;
  err = rpm->GetHeaderStr(RPMTAG_NAME, &name);
  if (err != rpm_helper::RPM_SUCCESS) {
    std::cout << rpm_helper::ErrorToString(err) << "\n";
  }

  std::cout << "name: " << name << "\n";
}

grpc::Status Test(grpc::ServerContext *context,
                  const ::yumrepofs::v2::TestRequest *request,
                  ::yumrepofs::v2::TestResponse *response) {
  response->set_message("Hello, " + request->name() + "!");

  return grpc::Status::OK;
}

} // namespace resf::yumrepofs
