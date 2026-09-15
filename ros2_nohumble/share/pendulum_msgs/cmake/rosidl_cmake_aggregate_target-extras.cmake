# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target pendulum_msgs::pendulum_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${pendulum_msgs_TARGETS}.
if(pendulum_msgs_TARGETS AND NOT TARGET pendulum_msgs::pendulum_msgs)
  add_library(pendulum_msgs::pendulum_msgs INTERFACE IMPORTED)
  set_target_properties(pendulum_msgs::pendulum_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${pendulum_msgs_TARGETS}")
endif()
