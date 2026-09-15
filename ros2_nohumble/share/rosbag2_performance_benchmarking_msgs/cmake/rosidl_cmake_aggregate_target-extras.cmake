# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target rosbag2_performance_benchmarking_msgs::rosbag2_performance_benchmarking_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${rosbag2_performance_benchmarking_msgs_TARGETS}.
if(rosbag2_performance_benchmarking_msgs_TARGETS AND NOT TARGET rosbag2_performance_benchmarking_msgs::rosbag2_performance_benchmarking_msgs)
  add_library(rosbag2_performance_benchmarking_msgs::rosbag2_performance_benchmarking_msgs INTERFACE IMPORTED)
  set_target_properties(rosbag2_performance_benchmarking_msgs::rosbag2_performance_benchmarking_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${rosbag2_performance_benchmarking_msgs_TARGETS}")
endif()
