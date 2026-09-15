#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "osrf_testing_tools_cpp::test_runner" for configuration "RelWithDebInfo"
set_property(TARGET osrf_testing_tools_cpp::test_runner APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(osrf_testing_tools_cpp::test_runner PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/osrf_testing_tools_cpp/test_runner.exe"
  )

list(APPEND _cmake_import_check_targets osrf_testing_tools_cpp::test_runner )
list(APPEND _cmake_import_check_files_for_osrf_testing_tools_cpp::test_runner "${_IMPORT_PREFIX}/lib/osrf_testing_tools_cpp/test_runner.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
