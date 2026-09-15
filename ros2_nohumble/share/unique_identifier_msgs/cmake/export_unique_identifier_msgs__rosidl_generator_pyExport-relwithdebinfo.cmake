#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py" for configuration "RelWithDebInfo"
set_property(TARGET unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/unique_identifier_msgs__rosidl_generator_py.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_c;Python3::Python;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/unique_identifier_msgs__rosidl_generator_py.dll"
  )

list(APPEND _cmake_import_check_targets unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py "${_IMPORT_PREFIX}/lib/unique_identifier_msgs__rosidl_generator_py.lib" "${_IMPORT_PREFIX}/bin/unique_identifier_msgs__rosidl_generator_py.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
