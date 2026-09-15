#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "osrf_testing_tools_cpp::memory_tools" for configuration "RelWithDebInfo"
set_property(TARGET osrf_testing_tools_cpp::memory_tools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(osrf_testing_tools_cpp::memory_tools PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/memory_tools.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/memory_tools.dll"
  )

list(APPEND _cmake_import_check_targets osrf_testing_tools_cpp::memory_tools )
list(APPEND _cmake_import_check_files_for_osrf_testing_tools_cpp::memory_tools "${_IMPORT_PREFIX}/lib/memory_tools.lib" "${_IMPORT_PREFIX}/bin/memory_tools.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
