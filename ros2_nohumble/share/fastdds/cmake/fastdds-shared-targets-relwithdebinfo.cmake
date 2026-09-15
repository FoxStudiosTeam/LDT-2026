#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fastdds" for configuration "RelWithDebInfo"
set_property(TARGET fastdds APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(fastdds PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/fastdds-3.6.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "tinyxml2::tinyxml2"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/fastdds-3.6.dll"
  )

list(APPEND _cmake_import_check_targets fastdds )
list(APPEND _cmake_import_check_files_for_fastdds "${_IMPORT_PREFIX}/lib/fastdds-3.6.lib" "${_IMPORT_PREFIX}/bin/fastdds-3.6.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
