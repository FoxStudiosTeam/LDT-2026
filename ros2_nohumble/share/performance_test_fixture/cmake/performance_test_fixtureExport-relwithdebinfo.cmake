#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "performance_test_fixture::performance_test_fixture" for configuration "RelWithDebInfo"
set_property(TARGET performance_test_fixture::performance_test_fixture APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(performance_test_fixture::performance_test_fixture PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/performance_test_fixture.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/performance_test_fixture.dll"
  )

list(APPEND _cmake_import_check_targets performance_test_fixture::performance_test_fixture )
list(APPEND _cmake_import_check_files_for_performance_test_fixture::performance_test_fixture "${_IMPORT_PREFIX}/lib/performance_test_fixture.lib" "${_IMPORT_PREFIX}/bin/performance_test_fixture.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
