#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rcl_logging_spdlog::rcl_logging_spdlog" for configuration "RelWithDebInfo"
set_property(TARGET rcl_logging_spdlog::rcl_logging_spdlog APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rcl_logging_spdlog::rcl_logging_spdlog PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rcl_logging_spdlog.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils;rcutils::rcutils;spdlog::spdlog"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rcl_logging_spdlog.dll"
  )

list(APPEND _cmake_import_check_targets rcl_logging_spdlog::rcl_logging_spdlog )
list(APPEND _cmake_import_check_files_for_rcl_logging_spdlog::rcl_logging_spdlog "${_IMPORT_PREFIX}/lib/rcl_logging_spdlog.lib" "${_IMPORT_PREFIX}/bin/rcl_logging_spdlog.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
