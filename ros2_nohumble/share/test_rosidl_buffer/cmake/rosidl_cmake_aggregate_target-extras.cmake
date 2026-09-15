# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target test_rosidl_buffer::test_rosidl_buffer
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${test_rosidl_buffer_TARGETS}.
if(test_rosidl_buffer_TARGETS AND NOT TARGET test_rosidl_buffer::test_rosidl_buffer)
  add_library(test_rosidl_buffer::test_rosidl_buffer INTERFACE IMPORTED)
  set_target_properties(test_rosidl_buffer::test_rosidl_buffer PROPERTIES
    INTERFACE_LINK_LIBRARIES "${test_rosidl_buffer_TARGETS}")
endif()
