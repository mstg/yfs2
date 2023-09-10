"""An openssl build file based on a snippet found in the github issue:
https://github.com/bazelbuild/rules_foreign_cc/issues/337

Note that the $(PERL) "make variable" (https://docs.bazel.build/versions/main/be/make-variables.html)
is populated by the perl toolchain provided by rules_perl.
"""

load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

# Read https://wiki.openssl.org/index.php/Compilation_and_Installation

filegroup(
    name = "all",
    srcs = glob(
        include = ["**"],
        exclude = ["*.bazel"],
    ),
)

CONFIGURE_OPTIONS = [
    "no-comp",
    "no-idea",
    "no-weak-ssl-ciphers",
]

configure_make(
    name = "openssl",
    configure_command = "config",
    configure_in_place = True,
    configure_options = select({
        "@platforms//os:macos": [
            "no-shared",
            "ARFLAGS=r",
        ] + CONFIGURE_OPTIONS,
        "//conditions:default": [
            "no-shared",
        ] + CONFIGURE_OPTIONS,
    }),
    env = select({
        "@platforms//os:macos": {
            "AR": "",
        },
        "//conditions:default": {},
    }),
    includes = [
        "include",
    ],
    lib_name = "openssl",
    lib_source = "@openssl//:all",
    out_lib_dir = "lib",
    out_static_libs = [
        "libssl.a",
        "libcrypto.a",
    ],
    visibility = ["//visibility:public"],
)
