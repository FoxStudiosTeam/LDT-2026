#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_fastrtps_cpp::rmw_fastrtps_cpp" for configuration "RelWithDebInfo"
set_property(TARGET rmw_fastrtps_cpp::rmw_fastrtps_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_fastrtps_cpp::rmw_fastrtps_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_fastrtps_cpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils;rcutils::rcutils;rosidl_buffer_backend_registry::rosidl_buffer_backend_registry;rmw_dds_common::rmw_dds_common_library;rosidl_dynamic_typesupport::rosidl_dynamic_typesupport;rosidl_dynamic_typesupport_fastrtps::rosidl_dynamic_typesupport_fastrtps;rosidl_typesupport_fastrtps_c::rosidl_typesupport_fastrtps_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_fastrtps_cpp.dll"
  )

list(APPEND _cmake_import_check_targets rmw_fastrtps_cpp::rmw_fastrtps_cpp )
list(APPEND _cmake_import_check_files_for_rmw_fastrtps_cpp::rmw_fastrtps_cpp "${_IMPORT_PREFIX}/lib/rmw_fastrtps_cpp.lib" "${_IMPORT_PREFIX}/bin/rmw_fastrtps_cpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
