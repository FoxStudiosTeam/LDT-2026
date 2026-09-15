#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rclcpp::rclcpp" for configuration "RelWithDebInfo"
set_property(TARGET rclcpp::rclcpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rclcpp::rclcpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rclcpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp;rcl_logging_interface::rcl_logging_interface"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rclcpp.dll"
  )

list(APPEND _cmake_import_check_targets rclcpp::rclcpp )
list(APPEND _cmake_import_check_files_for_rclcpp::rclcpp "${_IMPORT_PREFIX}/lib/rclcpp.lib" "${_IMPORT_PREFIX}/bin/rclcpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
