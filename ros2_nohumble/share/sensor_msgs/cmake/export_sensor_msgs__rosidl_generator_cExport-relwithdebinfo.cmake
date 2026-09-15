#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sensor_msgs::sensor_msgs__rosidl_generator_c" for configuration "RelWithDebInfo"
set_property(TARGET sensor_msgs::sensor_msgs__rosidl_generator_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(sensor_msgs::sensor_msgs__rosidl_generator_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/sensor_msgs__rosidl_generator_c.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/sensor_msgs__rosidl_generator_c.dll"
  )

list(APPEND _cmake_import_check_targets sensor_msgs::sensor_msgs__rosidl_generator_c )
list(APPEND _cmake_import_check_files_for_sensor_msgs::sensor_msgs__rosidl_generator_c "${_IMPORT_PREFIX}/lib/sensor_msgs__rosidl_generator_c.lib" "${_IMPORT_PREFIX}/bin/sensor_msgs__rosidl_generator_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
