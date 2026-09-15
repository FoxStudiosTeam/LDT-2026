# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ros2cli_test_interfaces::ros2cli_test_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ros2cli_test_interfaces_TARGETS}.
if(ros2cli_test_interfaces_TARGETS AND NOT TARGET ros2cli_test_interfaces::ros2cli_test_interfaces)
  add_library(ros2cli_test_interfaces::ros2cli_test_interfaces INTERFACE IMPORTED)
  set_target_properties(ros2cli_test_interfaces::ros2cli_test_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ros2cli_test_interfaces_TARGETS}")
endif()
