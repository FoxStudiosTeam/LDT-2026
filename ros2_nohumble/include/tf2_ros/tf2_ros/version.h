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

#ifndef TF2_ROS__VERSION_H_
#define TF2_ROS__VERSION_H_

/// \def TF2_ROS_VERSION_MAJOR
/// Defines TF2_ROS major version number
#define TF2_ROS_VERSION_MAJOR (0)

/// \def TF2_ROS_VERSION_MINOR
/// Defines TF2_ROS minor version number
#define TF2_ROS_VERSION_MINOR (46)

/// \def TF2_ROS_VERSION_PATCH
/// Defines TF2_ROS version patch number
#define TF2_ROS_VERSION_PATCH (3)

/// \def TF2_ROS_VERSION_STR
/// Defines TF2_ROS version string
#define TF2_ROS_VERSION_STR "0.46.3"

/// \def TF2_ROS_VERSION_GTE
/// Defines a macro to check whether the version of TF2_ROS is greater than or equal to
/// the given version triple.
#define TF2_ROS_VERSION_GTE(major, minor, patch) ( \
     (major < TF2_ROS_VERSION_MAJOR) ? true \
     : ((major > TF2_ROS_VERSION_MAJOR) ? false \
     : ((minor < TF2_ROS_VERSION_MINOR) ? true \
     : ((minor > TF2_ROS_VERSION_MINOR) ? false \
     : ((patch < TF2_ROS_VERSION_PATCH) ? true \
     : ((patch > TF2_ROS_VERSION_PATCH) ? false \
     : true))))))

#endif  // TF2_ROS__VERSION_H_
