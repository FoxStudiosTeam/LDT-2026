# Copyright 2025 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include(FindPackageHandleStandardArgs)
find_package(yaml-cpp CONFIG QUIET)
if(yaml-cpp_FOUND)
  find_package_handle_standard_args(yaml-cpp FOUND_VAR yaml-cpp_FOUND CONFIG_MODE)
  if (NOT TARGET yaml-cpp::yaml-cpp)
    add_library(yaml-cpp::yaml-cpp ALIAS yaml-cpp)
  endif()
else()
  # Otherwise, rely on pkg-config
  find_package(PkgConfig QUIET)

  if(PKG_CONFIG_FOUND)
    pkg_check_modules(YAML_PKG_CONFIG IMPORTED_TARGET yaml-cpp-0.8)
    find_package_handle_standard_args(yaml-cpp DEFAULT_MSG YAML_PKG_CONFIG_FOUND)

    if(yaml-cpp_FOUND)
      if(NOT TARGET yaml-cpp)
        add_library(yaml-cpp INTERFACE IMPORTED)
        set_property(TARGET yaml-cpp PROPERTY INTERFACE_LINK_LIBRARIES PkgConfig::YAML_PKG_CONFIG)
      endif()
      set(yaml-cpp_LIBRARIES yaml-cpp)
      set(yaml-cpp_VERSION ${YAML-CPP_PKG_CONFIG_VERSION})
    endif()
  endif()
endif()
