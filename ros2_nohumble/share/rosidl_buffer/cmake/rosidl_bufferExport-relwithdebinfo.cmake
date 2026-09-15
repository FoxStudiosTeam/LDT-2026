#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_buffer::rosidl_buffer" for configuration "RelWithDebInfo"
set_property(TARGET rosidl_buffer::rosidl_buffer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosidl_buffer::rosidl_buffer PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosidl_buffer.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosidl_buffer.dll"
  )

list(APPEND _cmake_import_check_targets rosidl_buffer::rosidl_buffer )
list(APPEND _cmake_import_check_files_for_rosidl_buffer::rosidl_buffer "${_IMPORT_PREFIX}/lib/rosidl_buffer.lib" "${_IMPORT_PREFIX}/bin/rosidl_buffer.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
