#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_logging_implementation::rcl_logging_implementation" for configuration "RelWithDebInfo"
set_property(TARGET rcl_logging_implementation::rcl_logging_implementation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rcl_logging_implementation::rcl_logging_implementation PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rcl_logging_implementation.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rcl_logging_implementation.dll"
  )

list(APPEND _cmake_import_check_targets rcl_logging_implementation::rcl_logging_implementation )
list(APPEND _cmake_import_check_files_for_rcl_logging_implementation::rcl_logging_implementation "${_IMPORT_PREFIX}/lib/rcl_logging_implementation.lib" "${_IMPORT_PREFIX}/bin/rcl_logging_implementation.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
