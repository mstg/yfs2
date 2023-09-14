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
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "etcdv3",
    srcs = [
        "etcdv3.cc",
        "etcdv3_lease.cc",
        "etcdv3_lock.cc",
    ],
    hdrs = [
        "etcdv3.h",
        "etcdv3_lease.h",
        "etcdv3_lock.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/etcd/api/etcdserverpb:rpc",
        "//third_party/etcd/api/v3lockpb:v3lock",
    ],
)

cc_library(
    name = "rpm",
    srcs = [
        "rpm.cc",
    ],
    hdrs = [
        "rpm.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@rpm",
    ],
)

cc_library(
    name = "storage",
    hdrs = ["storage.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/status",
    ],
)

cc_library(
    name = "storage_s3",
    srcs = ["storage_s3.cc"],
    hdrs = ["storage_s3.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":storage",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings:str_format",
        "@minio_cpp",
    ],
)
