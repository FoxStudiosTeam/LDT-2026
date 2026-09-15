#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosbag2_cpp::rosbag2_cpp" for configuration "RelWithDebInfo"
set_property(TARGET rosbag2_cpp::rosbag2_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosbag2_cpp::rosbag2_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosbag2_cpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp;rosidl_typesupport_cpp::rosidl_typesupport_cpp"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosbag2_cpp.dll"
  )

list(APPEND _cmake_import_check_targets rosbag2_cpp::rosbag2_cpp )
list(APPEND _cmake_import_check_files_for_rosbag2_cpp::rosbag2_cpp "${_IMPORT_PREFIX}/lib/rosbag2_cpp.lib" "${_IMPORT_PREFIX}/bin/rosbag2_cpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
