#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_connextdds_common::rmw_connextdds_common_pro" for configuration "RelWithDebInfo"
set_property(TARGET rmw_connextdds_common::rmw_connextdds_common_pro APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_connextdds_common::rmw_connextdds_common_pro PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_connextdds_common_pro.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_connextdds_common_pro.dll"
  )

list(APPEND _cmake_import_check_targets rmw_connextdds_common::rmw_connextdds_common_pro )
list(APPEND _cmake_import_check_files_for_rmw_connextdds_common::rmw_connextdds_common_pro "${_IMPORT_PREFIX}/lib/rmw_connextdds_common_pro.lib" "${_IMPORT_PREFIX}/bin/rmw_connextdds_common_pro.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
