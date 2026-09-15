#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rclcpp_action::rclcpp_action" for configuration "RelWithDebInfo"
set_property(TARGET rclcpp_action::rclcpp_action APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rclcpp_action::rclcpp_action PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rclcpp_action.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rcpputils::rcpputils"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rclcpp_action.dll"
  )

list(APPEND _cmake_import_check_targets rclcpp_action::rclcpp_action )
list(APPEND _cmake_import_check_files_for_rclcpp_action::rclcpp_action "${_IMPORT_PREFIX}/lib/rclcpp_action.lib" "${_IMPORT_PREFIX}/bin/rclcpp_action.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
