#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosgraph_msgs::rosgraph_msgs__rosidl_generator_py" for configuration "RelWithDebInfo"
set_property(TARGET rosgraph_msgs::rosgraph_msgs__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosgraph_msgs::rosgraph_msgs__rosidl_generator_py PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosgraph_msgs__rosidl_generator_py.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rosgraph_msgs::rosgraph_msgs__rosidl_generator_c;Python3::Python;rosgraph_msgs::rosgraph_msgs__rosidl_typesupport_c;builtin_interfaces::builtin_interfaces__rosidl_generator_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_cpp;builtin_interfaces::builtin_interfaces__rosidl_generator_py;rcl_interfaces::rcl_interfaces__rosidl_generator_c;rcl_interfaces::rcl_interfaces__rosidl_typesupport_fastrtps_c;rcl_interfaces::rcl_interfaces__rosidl_typesupport_introspection_c;rcl_interfaces::rcl_interfaces__rosidl_typesupport_c;rcl_interfaces::rcl_interfaces__rosidl_typesupport_fastrtps_cpp;rcl_interfaces::rcl_interfaces__rosidl_typesupport_introspection_cpp;rcl_interfaces::rcl_interfaces__rosidl_typesupport_cpp;rcl_interfaces::rcl_interfaces__rosidl_generator_py;service_msgs::service_msgs__rosidl_generator_c;service_msgs::service_msgs__rosidl_typesupport_fastrtps_c;service_msgs::service_msgs__rosidl_typesupport_fastrtps_cpp;service_msgs::service_msgs__rosidl_typesupport_introspection_c;service_msgs::service_msgs__rosidl_typesupport_c;service_msgs::service_msgs__rosidl_typesupport_introspection_cpp;service_msgs::service_msgs__rosidl_typesupport_cpp;service_msgs::service_msgs__rosidl_generator_py"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosgraph_msgs__rosidl_generator_py.dll"
  )

list(APPEND _cmake_import_check_targets rosgraph_msgs::rosgraph_msgs__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_rosgraph_msgs::rosgraph_msgs__rosidl_generator_py "${_IMPORT_PREFIX}/lib/rosgraph_msgs__rosidl_generator_py.lib" "${_IMPORT_PREFIX}/bin/rosgraph_msgs__rosidl_generator_py.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
