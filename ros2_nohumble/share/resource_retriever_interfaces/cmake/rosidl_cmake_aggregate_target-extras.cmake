# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target resource_retriever_interfaces::resource_retriever_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${resource_retriever_interfaces_TARGETS}.
if(resource_retriever_interfaces_TARGETS AND NOT TARGET resource_retriever_interfaces::resource_retriever_interfaces)
  add_library(resource_retriever_interfaces::resource_retriever_interfaces INTERFACE IMPORTED)
  set_target_properties(resource_retriever_interfaces::resource_retriever_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${resource_retriever_interfaces_TARGETS}")
endif()
