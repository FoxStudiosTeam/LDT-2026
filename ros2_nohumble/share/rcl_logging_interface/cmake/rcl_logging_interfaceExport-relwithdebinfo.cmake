#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_logging_interface::rcl_logging_interface" for configuration "RelWithDebInfo"
set_property(TARGET rcl_logging_interface::rcl_logging_interface APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rcl_logging_interface::rcl_logging_interface PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rcl_logging_interface.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rcl_logging_interface.dll"
  )

list(APPEND _cmake_import_check_targets rcl_logging_interface::rcl_logging_interface )
list(APPEND _cmake_import_check_files_for_rcl_logging_interface::rcl_logging_interface "${_IMPORT_PREFIX}/lib/rcl_logging_interface.lib" "${_IMPORT_PREFIX}/bin/rcl_logging_interface.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
