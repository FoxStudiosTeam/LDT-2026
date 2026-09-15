#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "osrf_testing_tools_cpp::memory_tools_interpose" for configuration "RelWithDebInfo"
set_property(TARGET osrf_testing_tools_cpp::memory_tools_interpose APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(osrf_testing_tools_cpp::memory_tools_interpose PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/memory_tools_interpose.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/memory_tools_interpose.dll"
  )

list(APPEND _cmake_import_check_targets osrf_testing_tools_cpp::memory_tools_interpose )
list(APPEND _cmake_import_check_files_for_osrf_testing_tools_cpp::memory_tools_interpose "${_IMPORT_PREFIX}/lib/memory_tools_interpose.lib" "${_IMPORT_PREFIX}/bin/memory_tools_interpose.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
