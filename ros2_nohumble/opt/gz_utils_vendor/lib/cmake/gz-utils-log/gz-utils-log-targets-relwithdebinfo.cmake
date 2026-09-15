#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gz-utils::gz-utils-log" for configuration "RelWithDebInfo"
set_property(TARGET gz-utils::gz-utils-log APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gz-utils::gz-utils-log PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/gz-utils-log.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/gz-utils-log.dll"
  )

list(APPEND _cmake_import_check_targets gz-utils::gz-utils-log )
list(APPEND _cmake_import_check_files_for_gz-utils::gz-utils-log "${_IMPORT_PREFIX}/lib/gz-utils-log.lib" "${_IMPORT_PREFIX}/bin/gz-utils-log.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
