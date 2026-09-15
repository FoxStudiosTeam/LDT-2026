# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target rmw_dds_common::rmw_dds_common
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${rmw_dds_common_TARGETS}.
if(rmw_dds_common_TARGETS AND NOT TARGET rmw_dds_common::rmw_dds_common)
  add_library(rmw_dds_common::rmw_dds_common INTERFACE IMPORTED)
  set_target_properties(rmw_dds_common::rmw_dds_common PROPERTIES
    INTERFACE_LINK_LIBRARIES "${rmw_dds_common_TARGETS}")
endif()
