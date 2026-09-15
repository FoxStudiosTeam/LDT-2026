#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "robot_state_publisher::robot_state_publisher_node" for configuration "RelWithDebInfo"
set_property(TARGET robot_state_publisher::robot_state_publisher_node APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(robot_state_publisher::robot_state_publisher_node PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/robot_state_publisher_node.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "kdl_parser::kdl_parser"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/robot_state_publisher_node.dll"
  )

list(APPEND _cmake_import_check_targets robot_state_publisher::robot_state_publisher_node )
list(APPEND _cmake_import_check_files_for_robot_state_publisher::robot_state_publisher_node "${_IMPORT_PREFIX}/lib/robot_state_publisher_node.lib" "${_IMPORT_PREFIX}/bin/robot_state_publisher_node.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
