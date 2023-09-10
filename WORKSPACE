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
    build_file = "//third_party:boringssl.BUILD",
    # maintenance-git(boringssl.googlesource.com/boringssl, main-with-bazel)
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

# ------------------------------------------------------------------------------
# curl
# ------------------------------------------------------------------------------
http_archive(
    name = "curl",
    build_file = "//third_party/tensorflow:curl.BUILD",
    sha256 = "f98bdb06c0f52bdd19e63c4a77b5eb19b243bcbbd0f5b002b9f3cba7295a3a42",
    strip_prefix = "curl-8.2.1",
    urls = ["https://curl.haxx.se/download/curl-8.2.1.tar.gz"],
)

# ------------------------------------------------------------------------------
# curlpp
# ------------------------------------------------------------------------------
http_archive(
    name = "curlpp",
    build_file = "//third_party:curlpp.BUILD",
    sha256 = "f62bcd784c186ee19138424c4a5983927632059a88bc0056dd3beb612c6c7e2b",
    strip_prefix = "curlpp-1d8c7876cc81d7d125b663066282b207d9cbfe9a",
    urls = ["https://github.com/jpbarrette/curlpp/archive/1d8c7876cc81d7d125b663066282b207d9cbfe9a.tar.gz"],
)

# ------------------------------------------------------------------------------
# inih
# ------------------------------------------------------------------------------
http_archive(
    name = "inih",
    build_file = "//third_party:inih.BUILD",
    sha256 = "97eb803dbf3af5438dfb3db06509111f3b0927b25f12dc51df3ea084c7ff705c",
    strip_prefix = "inih-4e618f77d4bae216865c5abd972d99b1ba5031e2",
    urls = ["https://github.com/benhoyt/inih/archive/4e618f77d4bae216865c5abd972d99b1ba5031e2.tar.gz"],
)

# ------------------------------------------------------------------------------
# nlohmann_json
# ------------------------------------------------------------------------------
http_archive(
    name = "nlohmann_json",
    sha256 = "f35423aa4e28aca9b5844f01eaee24d36515e32e6db30e19f3ccd07120bd7619",
    strip_prefix = "json-836b7beca4b62e2a99465edef44066b7401fd704",
    urls = ["https://github.com/nlohmann/json/archive/836b7beca4b62e2a99465edef44066b7401fd704.tar.gz"],
)

# ------------------------------------------------------------------------------
# pugixml
# ------------------------------------------------------------------------------
http_archive(
    name = "pugixml",
    build_file = "//third_party:pugixml.BUILD",
    sha256 = "56e43bbe2733cc149c7d50a6d11a65b3c4ed080b16bfa6050154e09b1c320ed0",
    strip_prefix = "pugixml-db78afc2b7d8f043b4bc6b185635d949ea2ed2a8",
    urls = ["https://github.com/zeux/pugixml/archive/db78afc2b7d8f043b4bc6b185635d949ea2ed2a8.tar.gz"],
)

# ------------------------------------------------------------------------------
# minio_cpp
# ------------------------------------------------------------------------------
http_archive(
    name = "minio_cpp",
    build_file = "//third_party/minio_cpp:minio_cpp.BUILD",
    sha256 = "42eccc8188fb084a21c9bd79e54fa91d3a8f93bba44de8e516263c14916e3f17",
    strip_prefix = "minio-cpp-c62d3b7f041f869714a8661d1ca0501e816c2ab3",
    urls = ["https://github.com/minio/minio-cpp/archive/c62d3b7f041f869714a8661d1ca0501e816c2ab3.tar.gz"],
)
