# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target turtlesim_msgs::turtlesim_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${turtlesim_msgs_TARGETS}.
if(turtlesim_msgs_TARGETS AND NOT TARGET turtlesim_msgs::turtlesim_msgs)
  add_library(turtlesim_msgs::turtlesim_msgs INTERFACE IMPORTED)
  set_target_properties(turtlesim_msgs::turtlesim_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${turtlesim_msgs_TARGETS}")
endif()
