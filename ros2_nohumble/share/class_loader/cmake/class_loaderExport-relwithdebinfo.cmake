#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "class_loader::class_loader" for configuration "RelWithDebInfo"
set_property(TARGET class_loader::class_loader APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(class_loader::class_loader PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/class_loader.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/class_loader.dll"
  )

list(APPEND _cmake_import_check_targets class_loader::class_loader )
list(APPEND _cmake_import_check_files_for_class_loader::class_loader "${_IMPORT_PREFIX}/lib/class_loader.lib" "${_IMPORT_PREFIX}/bin/class_loader.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
