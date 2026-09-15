#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "test_msgs::test_msgs__rosidl_typesupport_fastrtps_c" for configuration "RelWithDebInfo"
set_property(TARGET test_msgs::test_msgs__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(test_msgs::test_msgs__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/test_msgs__rosidl_typesupport_fastrtps_c.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/test_msgs__rosidl_typesupport_fastrtps_c.dll"
  )

list(APPEND _cmake_import_check_targets test_msgs::test_msgs__rosidl_typesupport_fastrtps_c )
list(APPEND _cmake_import_check_files_for_test_msgs::test_msgs__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/test_msgs__rosidl_typesupport_fastrtps_c.lib" "${_IMPORT_PREFIX}/bin/test_msgs__rosidl_typesupport_fastrtps_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
