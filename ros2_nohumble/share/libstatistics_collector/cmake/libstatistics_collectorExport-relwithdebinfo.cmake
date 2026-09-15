#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libstatistics_collector::libstatistics_collector" for configuration "RelWithDebInfo"
set_property(TARGET libstatistics_collector::libstatistics_collector APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(libstatistics_collector::libstatistics_collector PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libstatistics_collector.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libstatistics_collector.dll"
  )

list(APPEND _cmake_import_check_targets libstatistics_collector::libstatistics_collector )
list(APPEND _cmake_import_check_files_for_libstatistics_collector::libstatistics_collector "${_IMPORT_PREFIX}/lib/libstatistics_collector.lib" "${_IMPORT_PREFIX}/bin/libstatistics_collector.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
