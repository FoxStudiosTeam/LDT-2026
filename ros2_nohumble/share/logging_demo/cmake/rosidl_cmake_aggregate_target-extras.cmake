# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target logging_demo::logging_demo
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${logging_demo_TARGETS}.
if(logging_demo_TARGETS AND NOT TARGET logging_demo::logging_demo)
  add_library(logging_demo::logging_demo INTERFACE IMPORTED)
  set_target_properties(logging_demo::logging_demo PROPERTIES
    INTERFACE_LINK_LIBRARIES "${logging_demo_TARGETS}")
endif()
