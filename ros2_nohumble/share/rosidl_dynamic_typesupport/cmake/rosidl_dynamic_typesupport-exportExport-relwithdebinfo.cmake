#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_dynamic_typesupport::rosidl_dynamic_typesupport" for configuration "RelWithDebInfo"
set_property(TARGET rosidl_dynamic_typesupport::rosidl_dynamic_typesupport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosidl_dynamic_typesupport::rosidl_dynamic_typesupport PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosidl_dynamic_typesupport.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosidl_dynamic_typesupport.dll"
  )

list(APPEND _cmake_import_check_targets rosidl_dynamic_typesupport::rosidl_dynamic_typesupport )
list(APPEND _cmake_import_check_files_for_rosidl_dynamic_typesupport::rosidl_dynamic_typesupport "${_IMPORT_PREFIX}/lib/rosidl_dynamic_typesupport.lib" "${_IMPORT_PREFIX}/bin/rosidl_dynamic_typesupport.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
