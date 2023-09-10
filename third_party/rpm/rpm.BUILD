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
    src = "@//third_party/rpm:config.h",
    out = "config.h",
)

copy_file(
    name = "tagtbl",
    src = "@//third_party/rpm:tagtbl.C",
    out = "lib/tagtbl.C",
)

copy_file(
    name = "digest_boringssl",
    src = "@//third_party/rpm:digest_boringssl.c",
    out = "rpmio/digest_boringssl.c",
)

common_copts = [
    "-Iexternal/rpm",
    "-Iexternal/rpm/include",
    "-DHAVE_CONFIG_H",
    "-D_GNU_SOURCE",
    "-D_FILE_OFFSET_BITS=64",
]

cc_library(
    name = "rpm_headers",
    hdrs = glob(["include/rpm/*.h"]),
    copts = common_copts,
    strip_include_prefix = "include",
)

cc_library(
    name = "rpm_system_h",
    hdrs = [
        "debug.h",
        "system.h",
    ],
    copts = common_copts,
)

cc_library(
    name = "rpm_config_h",
    hdrs = [":config.h"],
    copts = common_copts,
    includes = ["."],
)

cc_library(
    name = "rpm_tagtbl_C",
    hdrs = [":lib/tagtbl.C"],
    copts = common_copts,
    includes = ["."],
)

cc_library(
    name = "rpmio",
    srcs = [
        "rpmio/argv.c",
        "rpmio/base64.c",
        "rpmio/digest.c",
        "rpmio/expression.c",
        "rpmio/lposix.c",
        "rpmio/macro.c",
        "rpmio/rgetopt.c",
        "rpmio/rpmfileutil.c",
        "rpmio/rpmglob.c",
        "rpmio/rpmhook.c",
        "rpmio/rpmio.c",
        "rpmio/rpmkeyring.c",
        "rpmio/rpmlog.c",
        "rpmio/rpmlua.c",
        "rpmio/rpmmalloc.c",
        "rpmio/rpmpgp.c",
        "rpmio/rpmpgp_internal.c",
        "rpmio/rpmsq.c",
        "rpmio/rpmstring.c",
        "rpmio/rpmstrpool.c",
        "rpmio/rpmsw.c",
        "rpmio/rpmver.c",
        "rpmio/rpmvercmp.c",
        "rpmio/url.c",
        ":rpmio/digest_boringssl.c",
    ],
    hdrs = [
        "rpmio/lposix.h",
        "rpmio/rpmhook.h",
        "rpmio/rpmio_internal.h",
        "rpmio/rpmlua.h",
        "rpmio/rpmmacro_internal.h",
        "rpmio/rpmpgp_internal.h",
        "rpmio/rpmpgpval.h",
        "rpmio/modemuncher.c",
    ],
    copts = common_copts,
    visibility = ["//visibility:public"],
    deps = [
        ":rpm_config_h",
        ":rpm_headers",
        ":rpm_system_h",
        "@boringssl//:ssl",
        "@popt",
        "@xz//:lzma",
        "@zlib",
        "@lua",
    ],
    linkstatic = True,
)

cc_library(
    name = "rpm",
    srcs = [
        "lib/backend/dbi.c",
        "lib/backend/dbiset.c",
        "lib/backend/dummydb.c",
        "lib/cpio.c",
        "lib/depends.c",
        "lib/formats.c",
        "lib/fprint.c",
        "lib/fsm.c",
        "lib/header.c",
        "lib/headerfmt.c",
        "lib/headerutil.c",
        "lib/manifest.c",
        "lib/order.c",
        "lib/package.c",
        "lib/poptALL.c",
        "lib/poptI.c",
        "lib/poptQV.c",
        "lib/psm.c",
        "lib/query.c",
        "lib/relocation.c",
        "lib/rpmal.c",
        "lib/rpmchecksig.c",
        "lib/rpmchroot.c",
        "lib/rpmdb.c",
        "lib/rpmds.c",
        "lib/rpmfi.c",
        "lib/rpmfs.c",
        "lib/rpmgi.c",
        "lib/rpminstall.c",
        "lib/rpmlead.c",
        "lib/rpmlock.c",
        "lib/rpmplugins.c",
        "lib/rpmprob.c",
        "lib/rpmps.c",
        "lib/rpmrc.c",
        "lib/rpmscript.c",
        "lib/rpmtd.c",
        "lib/rpmte.c",
        "lib/rpmtriggers.c",
        "lib/rpmts.c",
        "lib/rpmug.c",
        "lib/rpmvs.c",
        "lib/signature.c",
        "lib/tagexts.c",
        "lib/tagname.c",
        "lib/transaction.c",
        "lib/verify.c",
    ],
    hdrs = [
        "lib/backend/dbi.h",
        "lib/backend/dbiset.h",
        "lib/cpio.h",
        "lib/fprint.h",
        "lib/fsm.h",
        "lib/header_internal.h",
        "lib/manifest.h",
        "lib/misc.h",
        "lib/rpmal.h",
        "lib/rpmchroot.h",
        "lib/rpmdb_internal.h",
        "lib/rpmds_internal.h",
        "lib/rpmfi_internal.h",
        "lib/rpmfs.h",
        "lib/rpmgi.h",
        "lib/rpmlead.h",
        "lib/rpmlock.h",
        "lib/rpmplugin.h",
        "lib/rpmplugins.h",
        "lib/rpmscript.h",
        "lib/rpmte_internal.h",
        "lib/rpmtriggers.h",
        "lib/rpmts_internal.h",
        "lib/rpmug.h",
        "lib/rpmvs.h",
        "lib/signature.h",
        "lib/rpmhash.H",
        "lib/rpmhash.C",
    ],
    copts = common_copts + [
        "-Wno-unused-const-variable",
        "-Wno-format",
        "-Wno-enum-conversion",
        "-Wno-unused-variable",
        "-Iexternal/rpm",
    ] + select({
        "@platforms//os:linux": [
            "-DHAVE___PROGNAME",
            "-D__GLIBC__",
        ],
        "@platforms//os:macos": [
            "-D__APPLE__",
            "-DHAVE_SETPROGNAME",
        ],
    }),
    includes = [
        "include",
    ],
    linkstatic = True,
    deps = [
        ":rpm_tagtbl_C",
        ":rpmio",
        ":rpm_config_h",
        ":rpm_system_h",
        "@boringssl//:ssl",
        "@popt",
    ],
    visibility = ["//visibility:public"],
)
