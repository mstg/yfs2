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

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "mutation_server/mutation_server_impl.h"

DEFINE_string(listen_addr, "0.0.0.0", "Address to listen on");
DEFINE_int32(listen_port, 6771, "Port to listen on");

int main(int argc, char **argv) {
  // Log to stderr by default
  FLAGS_logtostderr = true;

  google::SetUsageMessage("yfs2_mutation_server");
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging("yfs2_mutation_server");

  grpc::EnableDefaultHealthCheckService(true);

  // Start the mutation server.
  std::string addr = FLAGS_listen_addr + ":" + std::to_string(FLAGS_listen_port);
  resf::yumrepofs::MutationServerImpl mutation_server;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
  builder.RegisterService(&mutation_server);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  LOG(INFO) << "Starting mutation server on " << FLAGS_listen_addr << ":"
            << FLAGS_listen_port;

  server->Wait();

  return EXIT_SUCCESS;
}
