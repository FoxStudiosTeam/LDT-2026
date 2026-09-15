#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_security_common::rmw_security_common_library" for configuration "RelWithDebInfo"
set_property(TARGET rmw_security_common::rmw_security_common_library APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_security_common::rmw_security_common_library PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_security_common.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_security_common.dll"
  )

list(APPEND _cmake_import_check_targets rmw_security_common::rmw_security_common_library )
list(APPEND _cmake_import_check_files_for_rmw_security_common::rmw_security_common_library "${_IMPORT_PREFIX}/lib/rmw_security_common.lib" "${_IMPORT_PREFIX}/bin/rmw_security_common.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
