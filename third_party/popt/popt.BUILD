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
    src = "@//third_party/popt:config.h",
    out = "config.h",
)

common_copts = [
    "-Wno-unused-const-variable",
    "-Wno-unused-variable",
    "-Wno-int-to-pointer-cast",
    "-Wno-int-conversion",
    "-Wno-unused-but-set-variable",
    "-Wno-gnu-alignof-expression",
    "-Wno-implicit-int",
    "-DHAVE_CONFIG_H=1",
    "-DHAVE_STPCPY=1",
    "-DHAVE_STRERROR=1",
    "-DHAVE_STDALIGN_H=1",
    "-DHAVE_SETUID=1",
    "-DHAVE_SETREUID=1",
    "-DHAVE_SRANDOM=1",
]

cc_library(
    name = "popt_config",
    hdrs = [":config.h"],
    copts = common_copts,
    visibility = ["//visibility:private"],
)

cc_library(
    name = "popt",
    srcs = glob([
        "src/*.c",
    ]),
    hdrs = glob([
        "src/*.h",
        "src/lookup3.c",
    ]),
    copts = select({
        "@platforms//os:linux": common_copts + [
            "-DHAVE_SECURE_GETENV=1",
            "-D__GLIBC__=1",
        ],
        "@platforms//os:macos": common_copts + [
            "-D__APPLE__=1",
        ],
    }),
    includes = [
        ".",
        "src",
    ],
    linkstatic = True,
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = [
        ":popt_config",
    ],
)
