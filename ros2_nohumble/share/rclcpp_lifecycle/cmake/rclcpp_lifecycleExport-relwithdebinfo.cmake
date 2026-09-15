#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rclcpp_lifecycle::rclcpp_lifecycle" for configuration "RelWithDebInfo"
set_property(TARGET rclcpp_lifecycle::rclcpp_lifecycle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rclcpp_lifecycle::rclcpp_lifecycle PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rclcpp_lifecycle.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rclcpp_lifecycle.dll"
  )

list(APPEND _cmake_import_check_targets rclcpp_lifecycle::rclcpp_lifecycle )
list(APPEND _cmake_import_check_files_for_rclcpp_lifecycle::rclcpp_lifecycle "${_IMPORT_PREFIX}/lib/rclcpp_lifecycle.lib" "${_IMPORT_PREFIX}/bin/rclcpp_lifecycle.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
