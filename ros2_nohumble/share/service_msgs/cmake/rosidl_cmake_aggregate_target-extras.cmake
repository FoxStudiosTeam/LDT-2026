# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target service_msgs::service_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${service_msgs_TARGETS}.
if(service_msgs_TARGETS AND NOT TARGET service_msgs::service_msgs)
  add_library(service_msgs::service_msgs INTERFACE IMPORTED)
  set_target_properties(service_msgs::service_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${service_msgs_TARGETS}")
endif()
