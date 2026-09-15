#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_zenoh_cpp::rmw_zenoh_cpp" for configuration "RelWithDebInfo"
set_property(TARGET rmw_zenoh_cpp::rmw_zenoh_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_zenoh_cpp::rmw_zenoh_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_zenoh_cpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp;fastcdr;rcpputils::rcpputils;rcutils::rcutils;rosidl_buffer_backend_registry::rosidl_buffer_backend_registry;rosidl_typesupport_fastrtps_c::rosidl_typesupport_fastrtps_c;rosidl_typesupport_fastrtps_cpp::rosidl_typesupport_fastrtps_cpp;rmw::rmw"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_zenoh_cpp.dll"
  )

list(APPEND _cmake_import_check_targets rmw_zenoh_cpp::rmw_zenoh_cpp )
list(APPEND _cmake_import_check_files_for_rmw_zenoh_cpp::rmw_zenoh_cpp "${_IMPORT_PREFIX}/lib/rmw_zenoh_cpp.lib" "${_IMPORT_PREFIX}/bin/rmw_zenoh_cpp.dll" )

# Import target "rmw_zenoh_cpp::rmw_zenoh_cpp_test_fixture" for configuration "RelWithDebInfo"
set_property(TARGET rmw_zenoh_cpp::rmw_zenoh_cpp_test_fixture APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_zenoh_cpp::rmw_zenoh_cpp_test_fixture PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_zenoh_cpp_test_fixture.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp;rcpputils::rcpputils"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_zenoh_cpp_test_fixture.dll"
  )

list(APPEND _cmake_import_check_targets rmw_zenoh_cpp::rmw_zenoh_cpp_test_fixture )
list(APPEND _cmake_import_check_files_for_rmw_zenoh_cpp::rmw_zenoh_cpp_test_fixture "${_IMPORT_PREFIX}/lib/rmw_zenoh_cpp_test_fixture.lib" "${_IMPORT_PREFIX}/bin/rmw_zenoh_cpp_test_fixture.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
