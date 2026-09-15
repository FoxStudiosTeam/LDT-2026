#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_lifecycle::rcl_lifecycle" for configuration "RelWithDebInfo"
set_property(TARGET rcl_lifecycle::rcl_lifecycle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rcl_lifecycle::rcl_lifecycle PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rcl_lifecycle.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcutils::rcutils;rosidl_runtime_c::rosidl_runtime_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rcl_lifecycle.dll"
  )

list(APPEND _cmake_import_check_targets rcl_lifecycle::rcl_lifecycle )
list(APPEND _cmake_import_check_files_for_rcl_lifecycle::rcl_lifecycle "${_IMPORT_PREFIX}/lib/rcl_lifecycle.lib" "${_IMPORT_PREFIX}/bin/rcl_lifecycle.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
