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
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "curlpp",
    srcs = [
        "src/curlpp/Easy.cpp",
        "src/curlpp/Exception.cpp",
        "src/curlpp/Form.cpp",
        "src/curlpp/Multi.cpp",
        "src/curlpp/OptionBase.cpp",
        "src/curlpp/Options.cpp",
        "src/curlpp/cURLpp.cpp",
        "src/curlpp/internal/CurlHandle.cpp",
        "src/curlpp/internal/OptionList.cpp",
        "src/curlpp/internal/OptionSetter.cpp",
        "src/curlpp/internal/SList.cpp",
    ],
    hdrs = [
        # curlpp
        "include/curlpp/Easy.hpp",
        "include/curlpp/Easy.inl",
        "include/curlpp/Exception.hpp",
        "include/curlpp/Form.hpp",
        "include/curlpp/Info.hpp",
        "include/curlpp/Info.inl",
        "include/curlpp/Infos.hpp",
        "include/curlpp/Multi.hpp",
        "include/curlpp/Option.hpp",
        "include/curlpp/Option.inl",
        "include/curlpp/OptionBase.hpp",
        "include/curlpp/Options.hpp",
        "include/curlpp/Types.hpp",
        "include/curlpp/cURLpp.hpp",
        "include/curlpp/internal/CurlHandle.hpp",
        "include/curlpp/internal/CurlHandle.inl",
        "include/curlpp/internal/OptionContainer.hpp",
        "include/curlpp/internal/OptionContainer.inl",
        "include/curlpp/internal/OptionContainerType.hpp",
        "include/curlpp/internal/OptionList.hpp",
        "include/curlpp/internal/OptionSetter.hpp",
        "include/curlpp/internal/OptionSetter.inl",
        "include/curlpp/internal/SList.hpp",

        # utilspp
        "include/utilspp/EmptyType.hpp",
        "include/utilspp/NonCopyable.hpp",
        "include/utilspp/NullType.hpp",
        "include/utilspp/SmartPtr.hpp",
        "include/utilspp/ThreadingFactoryMutex.hpp",
        "include/utilspp/ThreadingFactoryMutex.inl",
        "include/utilspp/ThreadingSingle.hpp",
        "include/utilspp/ThreadingSingle.inl",
        "include/utilspp/TypeList.hpp",
        "include/utilspp/TypeTrait.hpp",
        "include/utilspp/clone_ptr.hpp",
    ],
    deps = [
        "@curl",
    ],
    copts = [
        "-Iexternal/curlpp/include",
        "-Iexternal/curlpp/include/curlpp",
    ],
    includes = [
        "include",
    ],
    linkstatic = True,
    visibility = ["//visibility:public"],
)
