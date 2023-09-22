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
#include "absl/flags/usage.h"
#include "absl/flags/parse.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/health_check_service_interface.h"

#include "yfs2/common/flag.h"
#include "yfs2/mutation_server/impl.h"
#include "yfs2/storage_s3.h"
#include "yfs2/rpm.h"

YFS2_STRING_FLAG(listen_addr, "[::]", "Address to listen on");
YFS2_INT32_FLAG(listen_port, 6771, "Port to listen on");
YFS2_BOOL_FLAG(debug, false, "Enable debug features");

YFS2_STRING_FLAG(etcd_addr, "localhost:2379", "Etcd address");

// Storage options
YFS2_STRING_FLAG(s3_bucket, "", "S3 bucket");
YFS2_STRING_FLAG(s3_region, "us-east-1", "S3 region");
YFS2_OPTIONAL_STRING_FLAG(s3_access_key_id,
                          std::nullopt,
                          "S3 access key ID");
YFS2_OPTIONAL_STRING_FLAG(s3_secret_access_key,
                          std::nullopt,
                          "S3 secret access key");
YFS2_STRING_FLAG(s3_endpoint, "s3.amazonaws.com", "S3 endpoint");
YFS2_BOOL_FLAG(s3_endpoint_secure, true, "S3 endpoint secure");

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

  auto get_mustafa = storage->Get("Mustafa");
  if (get_mustafa.ok()) {
    LOG(INFO) << "Mustafa: " << get_mustafa.value();
  } else {
    LOG(ERROR) << "Mustafa not found";
  }

  auto rpm = yfs2::Rpm(true);
  auto err = rpm.Init("/tmp/kernel-core-4.18.0-477.21.1.el8_8.x86_64.rpm");
  if (!err.ok()) {
    LOG(FATAL) << "Failed to init RPM: " << err.message();
  }

  auto rpm2 = yfs2::Rpm(true);
  auto exp = rpm.ExportHeader();
  LOG(INFO) << "Header size: " << exp.value().second;
  if (!exp.ok()) {
    LOG(FATAL) << "Failed to export RPM header: " << exp.status().message();
  }
  err = rpm2.InitWithHeaderOnly(exp.value().first);
  if (!err.ok()) {
    LOG(FATAL) << "Failed to init RPM: " << err.message();
  }

  auto get_source_rpm = rpm2.GetHeaderStr(RPMTAG_SOURCERPM);
  if (get_source_rpm.ok()) {
    LOG(INFO) << "Source RPM: " << get_source_rpm.value();
  } else {
    LOG(ERROR) << "Source RPM not found";
  }

  auto res = etcd->GetKeyValuesWithPrefix("/test/asd/");
  if (!res.ok()) {
    LOG(FATAL) << "Failed to get key values with prefix: " << res.status().message();
  }

  for (auto &value : res.value()) {
    LOG(INFO) << "Value: " << value;
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
