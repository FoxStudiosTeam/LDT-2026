#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "example_interfaces::example_interfaces__rosidl_generator_py" for configuration "RelWithDebInfo"
set_property(TARGET example_interfaces::example_interfaces__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(example_interfaces::example_interfaces__rosidl_generator_py PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/example_interfaces__rosidl_generator_py.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "example_interfaces::example_interfaces__rosidl_generator_c;Python3::Python;example_interfaces::example_interfaces__rosidl_typesupport_c;service_msgs::service_msgs__rosidl_generator_c;service_msgs::service_msgs__rosidl_typesupport_fastrtps_c;service_msgs::service_msgs__rosidl_typesupport_fastrtps_cpp;service_msgs::service_msgs__rosidl_typesupport_introspection_c;service_msgs::service_msgs__rosidl_typesupport_c;service_msgs::service_msgs__rosidl_typesupport_introspection_cpp;service_msgs::service_msgs__rosidl_typesupport_cpp;service_msgs::service_msgs__rosidl_generator_py;builtin_interfaces::builtin_interfaces__rosidl_generator_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_c;builtin_interfaces::builtin_interfaces__rosidl_typesupport_fastrtps_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_introspection_cpp;builtin_interfaces::builtin_interfaces__rosidl_typesupport_cpp;builtin_interfaces::builtin_interfaces__rosidl_generator_py;action_msgs::action_msgs__rosidl_generator_c;action_msgs::action_msgs__rosidl_typesupport_fastrtps_c;action_msgs::action_msgs__rosidl_typesupport_fastrtps_cpp;action_msgs::action_msgs__rosidl_typesupport_introspection_c;action_msgs::action_msgs__rosidl_typesupport_c;action_msgs::action_msgs__rosidl_typesupport_introspection_cpp;action_msgs::action_msgs__rosidl_typesupport_cpp;action_msgs::action_msgs__rosidl_generator_py;unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_c;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_fastrtps_c;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_introspection_c;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_c;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_fastrtps_cpp;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_introspection_cpp;unique_identifier_msgs::unique_identifier_msgs__rosidl_typesupport_cpp;unique_identifier_msgs::unique_identifier_msgs__rosidl_generator_py"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/example_interfaces__rosidl_generator_py.dll"
  )

list(APPEND _cmake_import_check_targets example_interfaces::example_interfaces__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_example_interfaces::example_interfaces__rosidl_generator_py "${_IMPORT_PREFIX}/lib/example_interfaces__rosidl_generator_py.lib" "${_IMPORT_PREFIX}/bin/example_interfaces__rosidl_generator_py.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
