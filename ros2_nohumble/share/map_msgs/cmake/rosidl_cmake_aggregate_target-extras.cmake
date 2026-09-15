# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target map_msgs::map_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${map_msgs_TARGETS}.
if(map_msgs_TARGETS AND NOT TARGET map_msgs::map_msgs)
  add_library(map_msgs::map_msgs INTERFACE IMPORTED)
  set_target_properties(map_msgs::map_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${map_msgs_TARGETS}")
endif()
