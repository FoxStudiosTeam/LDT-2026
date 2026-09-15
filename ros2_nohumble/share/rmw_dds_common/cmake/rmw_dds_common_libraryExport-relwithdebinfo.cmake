#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_dds_common::rmw_dds_common_library" for configuration "RelWithDebInfo"
set_property(TARGET rmw_dds_common::rmw_dds_common_library APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_dds_common::rmw_dds_common_library PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_dds_common.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils;rosidl_runtime_c::rosidl_runtime_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_dds_common.dll"
  )

list(APPEND _cmake_import_check_targets rmw_dds_common::rmw_dds_common_library )
list(APPEND _cmake_import_check_files_for_rmw_dds_common::rmw_dds_common_library "${_IMPORT_PREFIX}/lib/rmw_dds_common.lib" "${_IMPORT_PREFIX}/bin/rmw_dds_common.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
