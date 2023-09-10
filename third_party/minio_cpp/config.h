// yfs2 (Yumrepofs2) virtual read-write-many Yum repository server
// Copyright (C) 2023 Mustafa Gezen
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef _MINIO_CONFIG_H
#define _MINIO_CONFIG_H

#define MINIO_CPP_MAJOR_VERSION X
#define MINIO_CPP_MINOR_VERSION Y
#define MINIO_CPP_PATCH_VERSION Z
#define MINIO_CPP_VERSION "X.Y.Z-GIT-YFS2"

#define DEFAULT_USER_AGENT "MinIO (Bazel-YFS2) minio-cpp/" MINIO_CPP_VERSION

#endif  // #ifndef _MINIO_CONFIG_H
