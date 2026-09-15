#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "camera_calibration_parsers::camera_calibration_parsers" for configuration "RelWithDebInfo"
set_property(TARGET camera_calibration_parsers::camera_calibration_parsers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(camera_calibration_parsers::camera_calibration_parsers PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/camera_calibration_parsers.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rclcpp::rclcpp;yaml-cpp::yaml-cpp"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/camera_calibration_parsers.dll"
  )

list(APPEND _cmake_import_check_targets camera_calibration_parsers::camera_calibration_parsers )
list(APPEND _cmake_import_check_files_for_camera_calibration_parsers::camera_calibration_parsers "${_IMPORT_PREFIX}/lib/camera_calibration_parsers.lib" "${_IMPORT_PREFIX}/bin/camera_calibration_parsers.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
