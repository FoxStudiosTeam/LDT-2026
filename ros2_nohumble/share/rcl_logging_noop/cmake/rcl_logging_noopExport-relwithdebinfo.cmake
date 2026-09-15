#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_logging_noop::rcl_logging_noop" for configuration "RelWithDebInfo"
set_property(TARGET rcl_logging_noop::rcl_logging_noop APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rcl_logging_noop::rcl_logging_noop PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rcl_logging_noop.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcutils::rcutils;rcl_logging_interface::rcl_logging_interface"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rcl_logging_noop.dll"
  )

list(APPEND _cmake_import_check_targets rcl_logging_noop::rcl_logging_noop )
list(APPEND _cmake_import_check_files_for_rcl_logging_noop::rcl_logging_noop "${_IMPORT_PREFIX}/lib/rcl_logging_noop.lib" "${_IMPORT_PREFIX}/bin/rcl_logging_noop.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
