#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c" for configuration "RelWithDebInfo"
set_property(TARGET lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/lifecycle_msgs__rosidl_typesupport_c.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rosidl_runtime_c::rosidl_runtime_c;rosidl_typesupport_c::rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/lifecycle_msgs__rosidl_typesupport_c.dll"
  )

list(APPEND _cmake_import_check_targets lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c )
list(APPEND _cmake_import_check_files_for_lifecycle_msgs::lifecycle_msgs__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/lifecycle_msgs__rosidl_typesupport_c.lib" "${_IMPORT_PREFIX}/bin/lifecycle_msgs__rosidl_typesupport_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
