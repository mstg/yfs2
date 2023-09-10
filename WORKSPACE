load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# ------------------------------------------------------------------------------
# rules_cc
# ------------------------------------------------------------------------------
http_archive(
    name = "rules_cc",
    sha256 = "ae46b722a8b8e9b62170f83bfb040cbf12adb732144e689985a66b26410a7d6f",
    strip_prefix = "rules_cc-0.0.8",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.8/rules_cc-0.0.8.tar.gz"],
)

# ------------------------------------------------------------------------------
# boringssl
# ------------------------------------------------------------------------------
git_repository(
    name = "boringssl",
    commit = "9f9457790106e37402dfaae893e24d80a8666edd",
    remote = "https://boringssl.googlesource.com/boringssl",
)

# ------------------------------------------------------------------------------
# rules_foreign_cc
# ------------------------------------------------------------------------------
http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a8000ce03dd9bb324bc9bb7f1f5d01debac406611f4d9fedd385192718804f0",
    strip_prefix = "rules_foreign_cc-60813d57a0e99be1a009c1a0e9627cdbe81fcd19",
    urls = ["https://github.com/bazelbuild/rules_foreign_cc/archive/60813d57a0e99be1a009c1a0e9627cdbe81fcd19.tar.gz"],
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# ------------------------------------------------------------------------------
# protobuf
# ------------------------------------------------------------------------------
http_archive(
    name = "com_google_protobuf",
    sha256 = "d0f5f605d0d656007ce6c8b5a82df3037e1d8fe8b121ed42e536f569dec16113",
    strip_prefix = "protobuf-3.14.0",
    urls = [
        "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v3.14.0.tar.gz",
        "https://github.com/protocolbuffers/protobuf/archive/v3.14.0.tar.gz",
    ],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

# ------------------------------------------------------------------------------
# googleapis
# ------------------------------------------------------------------------------
http_archive(
    name = "googleapis",
    sha256 = "9d1a930e767c93c825398b8f8692eca3fe353b9aaadedfbcf1fca2282c85df88",
    strip_prefix = "googleapis-64926d52febbf298cb82a8f472ade4a3969ba922",
    urls = [
        "https://github.com/googleapis/googleapis/archive/64926d52febbf298cb82a8f472ade4a3969ba922.zip",
    ],
)

load("@googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,
)

# ------------------------------------------------------------------------------
# grpc
# ------------------------------------------------------------------------------
_GRPC_VERSION = "1.52.1"  # https://github.com/grpc/grpc/releases/tag/v1.52.1

http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "ec125d7fdb77ecc25b01050a0d5d32616594834d3fe163b016768e2ae42a2df6",
    strip_prefix = "grpc-" + _GRPC_VERSION,
    urls = ["https://github.com/grpc/grpc/archive/refs/tags/v" + _GRPC_VERSION + ".tar.gz"],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

# ------------------------------------------------------------------------------
# gflags
# ------------------------------------------------------------------------------
http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
)

# ------------------------------------------------------------------------------
# glog
# ------------------------------------------------------------------------------
http_archive(
    name = "com_github_google_glog",
    sha256 = "122fb6b712808ef43fbf80f75c52a21c9760683dae470154f02bddfc61135022",
    strip_prefix = "glog-0.6.0",
    urls = ["https://github.com/google/glog/archive/v0.6.0.zip"],
)

# ------------------------------------------------------------------------------
# zlib
# ------------------------------------------------------------------------------
http_archive(
    name = "zlib",
    build_file = "//:third_party/protocolbuffers/zlib.BUILD",
    sha256 = "d14c38e313afc35a9a8760dadf26042f51ea0f5d154b0630a31da0540107fb98",
    strip_prefix = "zlib-1.2.13",
    urls = [
        "https://github.com/madler/zlib/releases/download/v1.2.13/zlib-1.2.13.tar.xz",
        "https://zlib.net/zlib-1.2.13.tar.xz",
    ],
)

# ------------------------------------------------------------------------------
# lua
# ------------------------------------------------------------------------------
http_archive(
    name = "lua",
    build_file = "//third_party/cartographer:lua.BUILD",
    sha256 = "b9e2e4aad6789b3b63a056d442f7b39f0ecfca3ae0f1fc0ae4e9614401b69f4b",
    strip_prefix = "lua-5.2.4",
    urls = [
        "https://mirror.bazel.build/www.lua.org/ftp/lua-5.2.4.tar.gz",
        "https://www.lua.org/ftp/lua-5.2.4.tar.gz",
    ],
)

# ------------------------------------------------------------------------------
# xz
# ------------------------------------------------------------------------------
http_archive(
    name = "xz",
    build_file = "//third_party:xz.BUILD",
    sha256 = "4c1d840f9fa5bbffcd2cdc61b108c947341f14c9eaaefd6b2ea29d679170f4e7",
    strip_prefix = "xz-5.4.4",
    urls = ["https://github.com/tukaani-project/xz/archive/v5.4.4.tar.gz"],
)

# ------------------------------------------------------------------------------
# popt
# ------------------------------------------------------------------------------
http_archive(
    name = "popt",
    build_file = "//third_party/popt:popt.BUILD",
    sha256 = "f12fbd849baa2ce7f2ab2621a324094469ea82d1609a6209235dd0854a9ca46a",
    strip_prefix = "popt-9a2e28a25af346f0f8f488b24a0975a005693999",
    urls = ["https://github.com/rpm-software-management/popt/archive/9a2e28a25af346f0f8f488b24a0975a005693999.tar.gz"],
)

# ------------------------------------------------------------------------------
# rpm
# ------------------------------------------------------------------------------
http_archive(
    name = "rpm",
    build_file = "//third_party/rpm:rpm.BUILD",
    sha256 = "c5a03a7fa00fee83c458b2fdbdb9a99375829691e90681e9888c8166e9887f3e",
    strip_prefix = "rpm-08ae4ee23e7b746c529abef8ddc86cf650177e69",
    urls = ["https://github.com/rpm-software-management/rpm/archive/08ae4ee23e7b746c529abef8ddc86cf650177e69.tar.gz"],
)
