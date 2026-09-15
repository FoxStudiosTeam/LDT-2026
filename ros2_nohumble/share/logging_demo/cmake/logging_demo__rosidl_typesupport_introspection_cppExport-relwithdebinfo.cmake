#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "logging_demo::logging_demo__rosidl_typesupport_introspection_cpp" for configuration "RelWithDebInfo"
set_property(TARGET logging_demo::logging_demo__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(logging_demo::logging_demo__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/logging_demo__rosidl_typesupport_introspection_cpp.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/logging_demo__rosidl_typesupport_introspection_cpp.dll"
  )

list(APPEND _cmake_import_check_targets logging_demo::logging_demo__rosidl_typesupport_introspection_cpp )
list(APPEND _cmake_import_check_files_for_logging_demo::logging_demo__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/logging_demo__rosidl_typesupport_introspection_cpp.lib" "${_IMPORT_PREFIX}/bin/logging_demo__rosidl_typesupport_introspection_cpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
