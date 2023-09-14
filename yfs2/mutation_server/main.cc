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
#include "absl/flags/flag.h"
#include "absl/flags/usage.h"
#include "absl/flags/parse.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/health_check_service_interface.h"

#include "yfs2/mutation_server/impl.h"
#include "yfs2/storage_s3.h"

ABSL_FLAG(std::string, listen_addr, "[::]", "Address to listen on");
ABSL_FLAG(int32_t, listen_port, 6771, "Port to listen on");
ABSL_FLAG(bool, debug, false, "Enable debug features");

ABSL_FLAG(std::string, etcd_addr, "localhost:2379", "Etcd address");

// Storage options
ABSL_FLAG(std::string, s3_bucket, "", "S3 bucket");
ABSL_FLAG(std::string, s3_region, "us-east-1", "S3 region");
ABSL_FLAG(std::optional<std::string>,
          s3_access_key_id,
          std::nullopt,
          "S3 access key ID");
ABSL_FLAG(std::optional<std::string>,
          s3_secret_access_key,
          std::nullopt,
          "S3 secret access key");
ABSL_FLAG(std::string, s3_endpoint, "s3.amazonaws.com", "S3 endpoint");
ABSL_FLAG(bool, s3_endpoint_secure, true, "S3 endpoint secure");

int main(int argc, char **argv) {
  absl::SetProgramUsageMessage("YFS2 mutation server");
  absl::ParseCommandLine(argc, argv);
  absl::InitializeLog();
  absl::SetStderrThreshold(absl::LogSeverityAtLeast::kInfo);

  bool debug = absl::GetFlag(FLAGS_debug);

  grpc::EnableDefaultHealthCheckService(true);

  std::string etcd_addr = absl::GetFlag(FLAGS_etcd_addr);
  auto etcd = std::make_shared<yfs2::EtcdClient>(etcd_addr);

  std::string s3_bucket = absl::GetFlag(FLAGS_s3_bucket);
  if (s3_bucket.empty()) {
    LOG(FATAL) << "S3 bucket must be specified";
  }

  std::string s3_region = absl::GetFlag(FLAGS_s3_region);
  std::optional<std::string> s3_access_key_id =
      absl::GetFlag(FLAGS_s3_access_key_id);
  std::optional<std::string> s3_secret_access_key =
      absl::GetFlag(FLAGS_s3_secret_access_key);
  std::string s3_endpoint = absl::GetFlag(FLAGS_s3_endpoint);
  bool s3_endpoint_secure = absl::GetFlag(FLAGS_s3_endpoint_secure);
  auto storage = std::make_shared<yfs2::StorageS3>(s3_bucket,
                                                   debug,
                                                   s3_region,
                                                   s3_access_key_id,
                                                   s3_secret_access_key,
                                                   s3_endpoint,
                                                   s3_endpoint_secure);

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
