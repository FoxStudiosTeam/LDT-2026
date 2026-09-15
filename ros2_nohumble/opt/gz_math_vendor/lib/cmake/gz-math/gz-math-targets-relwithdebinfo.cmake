#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gz-math::gz-math" for configuration "RelWithDebInfo"
set_property(TARGET gz-math::gz-math APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gz-math::gz-math PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/gz-math.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/gz-math.dll"
  )

list(APPEND _cmake_import_check_targets gz-math::gz-math )
list(APPEND _cmake_import_check_files_for_gz-math::gz-math "${_IMPORT_PREFIX}/lib/gz-math.lib" "${_IMPORT_PREFIX}/bin/gz-math.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
