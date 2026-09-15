#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tf2_ros::tf2_ros" for configuration "RelWithDebInfo"
set_property(TARGET tf2_ros::tf2_ros APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tf2_ros::tf2_ros PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/tf2_ros.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/tf2_ros.dll"
  )

list(APPEND _cmake_import_check_targets tf2_ros::tf2_ros )
list(APPEND _cmake_import_check_files_for_tf2_ros::tf2_ros "${_IMPORT_PREFIX}/lib/tf2_ros.lib" "${_IMPORT_PREFIX}/bin/tf2_ros.dll" )

# Import target "tf2_ros::static_transform_broadcaster_node" for configuration "RelWithDebInfo"
set_property(TARGET tf2_ros::static_transform_broadcaster_node APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tf2_ros::static_transform_broadcaster_node PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/static_transform_broadcaster_node.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/static_transform_broadcaster_node.dll"
  )

list(APPEND _cmake_import_check_targets tf2_ros::static_transform_broadcaster_node )
list(APPEND _cmake_import_check_files_for_tf2_ros::static_transform_broadcaster_node "${_IMPORT_PREFIX}/lib/static_transform_broadcaster_node.lib" "${_IMPORT_PREFIX}/bin/static_transform_broadcaster_node.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
