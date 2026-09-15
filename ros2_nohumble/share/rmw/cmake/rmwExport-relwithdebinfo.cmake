#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw::rmw" for configuration "RelWithDebInfo"
set_property(TARGET rmw::rmw APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw::rmw PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw.dll"
  )

list(APPEND _cmake_import_check_targets rmw::rmw )
list(APPEND _cmake_import_check_files_for_rmw::rmw "${_IMPORT_PREFIX}/lib/rmw.lib" "${_IMPORT_PREFIX}/bin/rmw.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
