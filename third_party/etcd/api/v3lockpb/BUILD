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
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "v3lock_proto",
    srcs = [
        "v3lock.proto",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/etcd/api/etcdserverpb:rpc_proto",
        "//third_party/gogoproto:gogo_proto",
        "@com_google_googleapis//google/api:annotations_proto",
    ],
)

cc_proto_library(
    name = "v3lock_cc_proto",
    visibility = ["//visibility:public"],
    deps = [
        ":v3lock_proto",
    ],
)

cc_grpc_library(
    name = "v3lock_cc_grpc",
    srcs = [":v3lock_proto"],
    grpc_only = True,
    visibility = ["//visibility:public"],
    deps = [":v3lock_cc_proto"],
)

cc_library(
    name = "v3lock",
    visibility = ["//visibility:public"],
    deps = [
        ":v3lock_cc_grpc",
        ":v3lock_cc_proto",
        "//third_party/etcd/api/etcdserverpb:rpc",
        "//third_party/gogoproto:gogo_cc_proto",
    ],
)
