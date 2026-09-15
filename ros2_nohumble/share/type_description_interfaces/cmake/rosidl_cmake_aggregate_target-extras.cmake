# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target type_description_interfaces::type_description_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${type_description_interfaces_TARGETS}.
if(type_description_interfaces_TARGETS AND NOT TARGET type_description_interfaces::type_description_interfaces)
  add_library(type_description_interfaces::type_description_interfaces INTERFACE IMPORTED)
  set_target_properties(type_description_interfaces::type_description_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${type_description_interfaces_TARGETS}")
endif()
