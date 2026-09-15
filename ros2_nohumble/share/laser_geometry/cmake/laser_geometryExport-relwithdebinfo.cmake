#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "laser_geometry::laser_geometry" for configuration "RelWithDebInfo"
set_property(TARGET laser_geometry::laser_geometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(laser_geometry::laser_geometry PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/laser_geometry.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rclcpp::rclcpp"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/laser_geometry.dll"
  )

list(APPEND _cmake_import_check_targets laser_geometry::laser_geometry )
list(APPEND _cmake_import_check_files_for_laser_geometry::laser_geometry "${_IMPORT_PREFIX}/lib/laser_geometry.lib" "${_IMPORT_PREFIX}/bin/laser_geometry.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
