#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_buffer_backend_registry::rosidl_buffer_backend_registry" for configuration "RelWithDebInfo"
set_property(TARGET rosidl_buffer_backend_registry::rosidl_buffer_backend_registry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosidl_buffer_backend_registry::rosidl_buffer_backend_registry PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosidl_buffer_backend_registry.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosidl_buffer_backend_registry.dll"
  )

list(APPEND _cmake_import_check_targets rosidl_buffer_backend_registry::rosidl_buffer_backend_registry )
list(APPEND _cmake_import_check_files_for_rosidl_buffer_backend_registry::rosidl_buffer_backend_registry "${_IMPORT_PREFIX}/lib/rosidl_buffer_backend_registry.lib" "${_IMPORT_PREFIX}/bin/rosidl_buffer_backend_registry.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
