// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CAMERA_INFO_MANAGER__VERSION_H_
#define CAMERA_INFO_MANAGER__VERSION_H_

/// \def CAMERA_INFO_MANAGER_VERSION_MAJOR
/// Defines CAMERA_INFO_MANAGER major version number
#define CAMERA_INFO_MANAGER_VERSION_MAJOR (7)

/// \def CAMERA_INFO_MANAGER_VERSION_MINOR
/// Defines CAMERA_INFO_MANAGER minor version number
#define CAMERA_INFO_MANAGER_VERSION_MINOR (0)

/// \def CAMERA_INFO_MANAGER_VERSION_PATCH
/// Defines CAMERA_INFO_MANAGER version patch number
#define CAMERA_INFO_MANAGER_VERSION_PATCH (3)

/// \def CAMERA_INFO_MANAGER_VERSION_STR
/// Defines CAMERA_INFO_MANAGER version string
#define CAMERA_INFO_MANAGER_VERSION_STR "7.0.3"

/// \def CAMERA_INFO_MANAGER_VERSION_GTE
/// Defines a macro to check whether the version of CAMERA_INFO_MANAGER is greater than or equal to
/// the given version triple.
#define CAMERA_INFO_MANAGER_VERSION_GTE(major, minor, patch) ( \
     (major < CAMERA_INFO_MANAGER_VERSION_MAJOR) ? true \
     : ((major > CAMERA_INFO_MANAGER_VERSION_MAJOR) ? false \
     : ((minor < CAMERA_INFO_MANAGER_VERSION_MINOR) ? true \
     : ((minor > CAMERA_INFO_MANAGER_VERSION_MINOR) ? false \
     : ((patch < CAMERA_INFO_MANAGER_VERSION_PATCH) ? true \
     : ((patch > CAMERA_INFO_MANAGER_VERSION_PATCH) ? false \
     : true))))))

#endif  // CAMERA_INFO_MANAGER__VERSION_H_
