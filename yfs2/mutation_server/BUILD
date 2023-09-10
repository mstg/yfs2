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
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "mutation_server_lib",
    srcs = ["impl.cc"],
    hdrs = ["impl.h"],
    deps = [
        "//yfs2:etcdv3",
        "//yfs2:rpm",
        "//yfs2:storage_s3",
        "//yumrepofs/v2:mutation_server_cc_grpc",
        "@com_google_absl//absl/cleanup",
    ],
)

cc_binary(
    name = "mutation_server",
    srcs = ["main.cc"],
    deps = [
        ":mutation_server_lib",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_google_glog//:glog",
        "@com_github_grpc_grpc//:grpc++",
    ],
)
