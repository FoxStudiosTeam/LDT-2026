#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_cyclonedds_cpp::rmw_cyclonedds_cpp" for configuration "RelWithDebInfo"
set_property(TARGET rmw_cyclonedds_cpp::rmw_cyclonedds_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rmw_cyclonedds_cpp::rmw_cyclonedds_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rmw_cyclonedds_cpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "CycloneDDS::ddsc;rcutils::rcutils;rcpputils::rcpputils;rmw_dds_common::rmw_dds_common_library;rmw_security_common::rmw_security_common_library;rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c;rosidl_typesupport_introspection_cpp::rosidl_typesupport_introspection_cpp;rosidl_runtime_c::rosidl_runtime_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rmw_cyclonedds_cpp.dll"
  )

list(APPEND _cmake_import_check_targets rmw_cyclonedds_cpp::rmw_cyclonedds_cpp )
list(APPEND _cmake_import_check_files_for_rmw_cyclonedds_cpp::rmw_cyclonedds_cpp "${_IMPORT_PREFIX}/lib/rmw_cyclonedds_cpp.lib" "${_IMPORT_PREFIX}/bin/rmw_cyclonedds_cpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
