# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target tf2_msgs::tf2_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${tf2_msgs_TARGETS}.
if(tf2_msgs_TARGETS AND NOT TARGET tf2_msgs::tf2_msgs)
  add_library(tf2_msgs::tf2_msgs INTERFACE IMPORTED)
  set_target_properties(tf2_msgs::tf2_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${tf2_msgs_TARGETS}")
endif()
