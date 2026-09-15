#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "example_interfaces::example_interfaces__rosidl_typesupport_introspection_c" for configuration "RelWithDebInfo"
set_property(TARGET example_interfaces::example_interfaces__rosidl_typesupport_introspection_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(example_interfaces::example_interfaces__rosidl_typesupport_introspection_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/example_interfaces__rosidl_typesupport_introspection_c.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/example_interfaces__rosidl_typesupport_introspection_c.dll"
  )

list(APPEND _cmake_import_check_targets example_interfaces::example_interfaces__rosidl_typesupport_introspection_c )
list(APPEND _cmake_import_check_files_for_example_interfaces::example_interfaces__rosidl_typesupport_introspection_c "${_IMPORT_PREFIX}/lib/example_interfaces__rosidl_typesupport_introspection_c.lib" "${_IMPORT_PREFIX}/bin/example_interfaces__rosidl_typesupport_introspection_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
