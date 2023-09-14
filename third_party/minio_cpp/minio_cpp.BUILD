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
load("@bazel_skylib//rules:copy_file.bzl", "copy_file")
load("@rules_cc//cc:defs.bzl", "cc_library")

copy_file(
    name = "config",
    src = "@//third_party/minio_cpp:config.h",
    out = "include/minio/config.h",
)

genrule(
    name = "patched_utils_h",
    srcs = ["include/minio/utils.h"],
    outs = ["include2/utils.h"],
    cmd = "echo '#include <openssl/mem.h>\n#include <openssl/bio.h>' > $@ && cat $< >> $@",
)

genrule(
    name = "patched_baseclient_h",
    srcs = ["include/minio/baseclient.h"],
    outs = ["include2/baseclient.h"],
    cmd = "echo '#define DEFAULT_USER_AGENT \"MinIO (Bazel-YFS2) minio-cpp/X-GIT\"' > $@ && cat $< >> $@",
)

cc_library(
    name = "custom_headers",
    srcs = [
        ":include2/utils.h",
        ":include2/baseclient.h",
    ],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "minio_cpp",
    srcs = [
        "src/args.cc",
        "src/baseclient.cc",
        "src/client.cc",
        "src/http.cc",
        "src/request.cc",
        "src/response.cc",
        "src/select.cc",
        "src/signer.cc",
        "src/types.cc",
        "src/utils.cc",
    ],
    hdrs = [
        "include/minio/args.h",
        "include/minio/client.h",
        "include/minio/credentials.h",
        "include/minio/error.h",
        "include/minio/http.h",
        "include/minio/providers.h",
        "include/minio/request.h",
        "include/minio/response.h",
        "include/minio/select.h",
        "include/minio/signer.h",
        "include/minio/sse.h",
        "include/minio/types.h",
        ":include/minio/config.h",
    ],
    deps = [
        "@curlpp",
        "@inih//:cpp",
        "@nlohmann_json//:json",
        "@boringssl//:ssl",
        "@boringssl//:crypto",
        "@pugixml",
        ":custom_headers",
    ],
    copts = [
        "-std=c++17",
        "-Iexternal/minio_cpp/include/minio",
        "-Iexternal/minio_cpp/include2",
        # This is a third party library, so don't need to pollute
        # build output with warnings.
        "-Wno-unused-variable",
        "-Wno-unused-but-set-variable",
        "-DHAVE_INTTYPES_H",
        "-DHAVE_STDINT_H",
        "-DHAVE_STDLIB_H",
        "-DHAVE_LIMITS_H",
        "-DHAVE_SYS_TYPES_H",
        "-DHAVE_STRTOIMAX_F",
        "-DHAVE_STRPTIME_F",
    ],
    includes = [
        "include",
        "include/minio",
        "include2",
    ],
    linkstatic = True,
    visibility = ["//visibility:public"],
)
