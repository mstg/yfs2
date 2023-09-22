# yfs2 (Yumrepofs2) virtual read-write-many Yum repository server
# Copyright (C) 2023 Mustafa Gezen
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "file_proto",
    srcs = [
        "file.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "mutation_server_proto",
    srcs = [
        "mutation_server.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "rpm_proto",
    srcs = [
        "rpm.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "module_proto",
    srcs = [
        "module.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "package_proto",
    srcs = [
        "package.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "read_server_proto",
    srcs = [
        "read_server.proto",
    ],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "repository_proto",
    srcs = [
        "repository.proto",
    ],
    visibility = ["//visibility:public"],
)

cc_proto_library(
    name = "file_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":file_proto"],
)

cc_proto_library(
    name = "mutation_server_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":mutation_server_proto"],
)

cc_grpc_library(
    name = "mutation_server_cc_grpc",
    srcs = [":mutation_server_proto"],
    grpc_only = True,
    visibility = ["//visibility:public"],
    deps = [":mutation_server_cc_proto"],
)

cc_proto_library(
    name = "rpm_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":rpm_proto"],
)

cc_proto_library(
    name = "module_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":module_proto"],
)

cc_proto_library(
    name = "package_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":package_proto"],
)

cc_proto_library(
    name = "read_server_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":read_server_proto"],
)

cc_grpc_library(
    name = "read_server_cc_grpc",
    srcs = [":read_server_proto"],
    grpc_only = True,
    visibility = ["//visibility:public"],
    deps = [":read_server_cc_proto"],
)

cc_proto_library(
    name = "repository_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":repository_proto"],
)
