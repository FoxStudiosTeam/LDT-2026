#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps" for configuration "RelWithDebInfo"
set_property(TARGET rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosidl_dynamic_typesupport_fastrtps.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosidl_dynamic_typesupport_fastrtps.dll"
  )

list(APPEND _cmake_import_check_targets rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps )
list(APPEND _cmake_import_check_files_for_rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps "${_IMPORT_PREFIX}/lib/rosidl_dynamic_typesupport_fastrtps.lib" "${_IMPORT_PREFIX}/bin/rosidl_dynamic_typesupport_fastrtps.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
