# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target rosbag2_interfaces::rosbag2_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${rosbag2_interfaces_TARGETS}.
if(rosbag2_interfaces_TARGETS AND NOT TARGET rosbag2_interfaces::rosbag2_interfaces)
  add_library(rosbag2_interfaces::rosbag2_interfaces INTERFACE IMPORTED)
  set_target_properties(rosbag2_interfaces::rosbag2_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${rosbag2_interfaces_TARGETS}")
endif()
