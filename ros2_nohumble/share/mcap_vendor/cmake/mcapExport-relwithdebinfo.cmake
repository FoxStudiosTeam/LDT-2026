#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mcap_vendor::mcap" for configuration "RelWithDebInfo"
set_property(TARGET mcap_vendor::mcap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(mcap_vendor::mcap PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/mcap.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/mcap.dll"
  )

list(APPEND _cmake_import_check_targets mcap_vendor::mcap )
list(APPEND _cmake_import_check_files_for_mcap_vendor::mcap "${_IMPORT_PREFIX}/lib/mcap.lib" "${_IMPORT_PREFIX}/bin/mcap.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
