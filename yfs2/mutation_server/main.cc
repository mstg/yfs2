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

#include "absl/log/log.h"
#include "absl/log/initialize.h"
#include "absl/log/globals.h"
#include "absl/log/log_sink.h"
#include "absl/flags/flag.h"
#include "absl/flags/usage.h"
#include "absl/flags/parse.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/health_check_service_interface.h"

#include "yfs2/mutation_server/impl.h"
#include "yfs2/storage_s3.h"

ABSL_FLAG(std::string, listen_addr, "0.0.0.0", "Address to listen on");
ABSL_FLAG(int32_t, listen_port, 6771, "Port to listen on");
ABSL_FLAG(bool, debug, false, "Enable debug features");

ABSL_FLAG(std::string, etcd_addr, "localhost:2379", "Etcd address");

int main(int argc, char **argv) {
  absl::SetProgramUsageMessage("YFS2 mutation server");
  absl::ParseCommandLine(argc, argv);
  absl::InitializeLog();
  absl::SetStderrThreshold(absl::LogSeverityAtLeast::kInfo);

  bool debug = absl::GetFlag(FLAGS_debug);

  grpc::EnableDefaultHealthCheckService(true);

  std::string etcd_addr = absl::GetFlag(FLAGS_etcd_addr);
  auto etcd = std::make_shared<yfs2::EtcdClient>(etcd_addr);

  auto storage = std::make_shared<yfs2::StorageS3>("mship",
                                                   debug,
                                                   "us-east-1",
                                                   "minioadmin",
                                                   "minioadmin",
                                                   "localhost:9100",
                                                   false);

  auto get_mustafa = storage->Get("Mustafa");
  if (get_mustafa.ok()) {
    LOG(INFO) << "Got Mustafa: " << get_mustafa.value();
  } else {
    LOG(ERROR) << "Failed to get Mustafa: " << get_mustafa.status();
  }

  yfs2::mutation_server::MutationServerImpl mutation_server(etcd, storage);

  std::string listen_addr = absl::GetFlag(FLAGS_listen_addr);
  int32_t listen_port = absl::GetFlag(FLAGS_listen_port);
  std::string listen_port_str = std::to_string(listen_port);
  std::string addr = listen_addr + ":" + listen_port_str;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
  builder.RegisterService(&mutation_server);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  LOG(INFO) << "Starting mutation server on " << listen_addr << ":"
            << listen_port_str;

  server->Wait();

  return EXIT_SUCCESS;
}
