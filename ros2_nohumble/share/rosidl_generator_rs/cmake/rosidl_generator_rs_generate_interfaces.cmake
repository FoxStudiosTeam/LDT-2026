# Copyright 2016-2017 Esteve Fernandez <esteve@apache.org>
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

set(_output_path
  "${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_rs/${PROJECT_NAME}")
set(_generated_common_rs_files "")

foreach(_idl_file ${rosidl_generate_interfaces_ABS_IDL_FILES})
  list(APPEND _idl_files ${_idl_file})
endforeach()

list(APPEND _generated_common_rs_files
  "${_output_path}/rust/src/lib.rs"
  "${_output_path}/rust/build.rs"
  "${_output_path}/rust/Cargo.toml"
)

set(_dependency_files "")
set(_dependencies "")
foreach(_pkg_name ${rosidl_generate_interfaces_DEPENDENCY_PACKAGE_NAMES})
  foreach(_idl_file ${${_pkg_name}_IDL_FILES})
    set(_abs_idl_file "${${_pkg_name}_DIR}/../${_idl_file}")
    normalize_path(_abs_idl_file "${_abs_idl_file}")
    list(APPEND _dependency_files "${_abs_idl_file}")
    list(APPEND _dependencies "${_pkg_name}:${_abs_idl_file}")
  endforeach()
endforeach()

set(target_dependencies
  "${rosidl_generator_rs_BIN}"
  ${rosidl_generator_rs_GENERATOR_FILES}
  "${rosidl_generator_rs_TEMPLATE_DIR}/action.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/action/rmw.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/build.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/Cargo.toml.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/lib.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/msg.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/msg/rmw.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/srv.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/srv/rmw.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/templates/msg_idiomatic.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/templates/msg_rmw.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/templates/srv_idiomatic.rs.em"
  "${rosidl_generator_rs_TEMPLATE_DIR}/templates/srv_rmw.rs.em"
  ${_idl_files}
  ${_dependency_files})
foreach(dep ${target_dependencies})
  if(NOT EXISTS "${dep}")
    message(FATAL_ERROR "Target dependency '${dep}' does not exist")
  endif()
endforeach()

set(generator_arguments_file "${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_rs__arguments.json")
rosidl_write_generator_arguments(
  "${generator_arguments_file}"
  PACKAGE_NAME "${PROJECT_NAME}"
  IDL_TUPLES "${rosidl_generate_interfaces_IDL_TUPLES}"
  ROS_INTERFACE_FILES "${_idl_files}"
  ROS_INTERFACE_DEPENDENCIES "${_dependencies}"
  OUTPUT_DIR "${_output_path}"
  TEMPLATE_DIR "${rosidl_generator_rs_TEMPLATE_DIR}"
  TARGET_DEPENDENCIES ${target_dependencies}
)

file(READ ${generator_arguments_file} contents)
string(REPLACE "\n}"
  ",\n  \"package_version\": \"${${PROJECT_NAME}_VERSION}\"\n}" contents ${contents})
file(WRITE ${generator_arguments_file} ${contents})

file(MAKE_DIRECTORY "${_output_path}")

set(_target_suffix "__rs")

# needed to avoid multiple calls to the Rust generator trick copied from
# https://github.com/ros2/rosidl/blob/master/rosidl_generator_py/cmake/rosidl_generator_py_generate_interfaces.cmake
set(_subdir "${CMAKE_CURRENT_BINARY_DIR}/${rosidl_generate_interfaces_TARGET}${_target_suffix}")
file(MAKE_DIRECTORY "${_subdir}")
file(READ "${rosidl_generator_rs_DIR}/custom_command.cmake" _custom_command)
file(WRITE "${_subdir}/CMakeLists.txt" "${_custom_command}")
add_subdirectory("${_subdir}" ${rosidl_generate_interfaces_TARGET}${_target_suffix})

add_dependencies(${rosidl_generate_interfaces_TARGET} ${rosidl_generate_interfaces_TARGET}${_target_suffix})

set_property(
  SOURCE
  ${_generated_common_rs_files}
  PROPERTY GENERATED 1)

set(_rsext_suffix "__rsext")
if(NOT rosidl_generate_interfaces_SKIP_INSTALL)
  install(
    DIRECTORY "${_output_path}/rust"
    DESTINATION "share/${PROJECT_NAME}"
  )
endif()

if(BUILD_TESTING AND rosidl_generate_interfaces_ADD_LINTER_TESTS)
  if(NOT _idl_files STREQUAL "")
  # TODO(esteve): add linters for Rust files
  endif()
endif()
