# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target rosbag2_test_msgdefs::rosbag2_test_msgdefs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${rosbag2_test_msgdefs_TARGETS}.
if(rosbag2_test_msgdefs_TARGETS AND NOT TARGET rosbag2_test_msgdefs::rosbag2_test_msgdefs)
  add_library(rosbag2_test_msgdefs::rosbag2_test_msgdefs INTERFACE IMPORTED)
  set_target_properties(rosbag2_test_msgdefs::rosbag2_test_msgdefs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${rosbag2_test_msgdefs_TARGETS}")
endif()
