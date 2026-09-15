#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_test_fixture_implementation::rmw_test_fixture_implementation" for configuration "RelWithDebInfo"
set_property(TARGET rmw_test_fixture_implementation::rmw_test_fixture_implementation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_test_fixture_implementation::rmw_test_fixture_implementation PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_test_fixture_implementation.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils;rcutils::rcutils;rmw::rmw"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_test_fixture_implementation.dll"
  )

list(APPEND _cmake_import_check_targets rmw_test_fixture_implementation::rmw_test_fixture_implementation )
list(APPEND _cmake_import_check_files_for_rmw_test_fixture_implementation::rmw_test_fixture_implementation "${_IMPORT_PREFIX}/lib/rmw_test_fixture_implementation.lib" "${_IMPORT_PREFIX}/bin/rmw_test_fixture_implementation.dll" )

# Import target "rmw_test_fixture_implementation::run_rmw_isolated" for configuration "RelWithDebInfo"
set_property(TARGET rmw_test_fixture_implementation::run_rmw_isolated APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_test_fixture_implementation::run_rmw_isolated PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_test_fixture_implementation/run_rmw_isolated.exe"
  )

list(APPEND _cmake_import_check_targets rmw_test_fixture_implementation::run_rmw_isolated )
list(APPEND _cmake_import_check_files_for_rmw_test_fixture_implementation::run_rmw_isolated "${_IMPORT_PREFIX}/lib/rmw_test_fixture_implementation/run_rmw_isolated.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
