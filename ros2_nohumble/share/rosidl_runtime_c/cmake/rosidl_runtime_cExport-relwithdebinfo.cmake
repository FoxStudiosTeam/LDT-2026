#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_runtime_c::rosidl_runtime_c" for configuration "RelWithDebInfo"
set_property(TARGET rosidl_runtime_c::rosidl_runtime_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosidl_runtime_c::rosidl_runtime_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosidl_runtime_c.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosidl_runtime_c.dll"
  )

list(APPEND _cmake_import_check_targets rosidl_runtime_c::rosidl_runtime_c )
list(APPEND _cmake_import_check_files_for_rosidl_runtime_c::rosidl_runtime_c "${_IMPORT_PREFIX}/lib/rosidl_runtime_c.lib" "${_IMPORT_PREFIX}/bin/rosidl_runtime_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
