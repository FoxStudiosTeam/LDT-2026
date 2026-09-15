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

#ifndef IMAGE_TRANSPORT__VERSION_H_
#define IMAGE_TRANSPORT__VERSION_H_

/// \def IMAGE_TRANSPORT_VERSION_MAJOR
/// Defines IMAGE_TRANSPORT major version number
#define IMAGE_TRANSPORT_VERSION_MAJOR (7)

/// \def IMAGE_TRANSPORT_VERSION_MINOR
/// Defines IMAGE_TRANSPORT minor version number
#define IMAGE_TRANSPORT_VERSION_MINOR (0)

/// \def IMAGE_TRANSPORT_VERSION_PATCH
/// Defines IMAGE_TRANSPORT version patch number
#define IMAGE_TRANSPORT_VERSION_PATCH (3)

/// \def IMAGE_TRANSPORT_VERSION_STR
/// Defines IMAGE_TRANSPORT version string
#define IMAGE_TRANSPORT_VERSION_STR "7.0.3"

/// \def IMAGE_TRANSPORT_VERSION_GTE
/// Defines a macro to check whether the version of IMAGE_TRANSPORT is greater than or equal to
/// the given version triple.
#define IMAGE_TRANSPORT_VERSION_GTE(major, minor, patch) ( \
     (major < IMAGE_TRANSPORT_VERSION_MAJOR) ? true \
     : ((major > IMAGE_TRANSPORT_VERSION_MAJOR) ? false \
     : ((minor < IMAGE_TRANSPORT_VERSION_MINOR) ? true \
     : ((minor > IMAGE_TRANSPORT_VERSION_MINOR) ? false \
     : ((patch < IMAGE_TRANSPORT_VERSION_PATCH) ? true \
     : ((patch > IMAGE_TRANSPORT_VERSION_PATCH) ? false \
     : true))))))

#endif  // IMAGE_TRANSPORT__VERSION_H_
