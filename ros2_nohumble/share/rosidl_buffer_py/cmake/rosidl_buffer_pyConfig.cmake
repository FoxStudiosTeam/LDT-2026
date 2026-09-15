# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rosidl_buffer_py_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rosidl_buffer_py_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rosidl_buffer_py_FOUND FALSE)
  elseif(NOT rosidl_buffer_py_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rosidl_buffer_py_FOUND FALSE)
  endif()
  return()
endif()
set(_rosidl_buffer_py_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rosidl_buffer_py_FIND_QUIETLY)
  message(STATUS "Found rosidl_buffer_py: 5.3.1 (${rosidl_buffer_py_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rosidl_buffer_py' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT rosidl_buffer_py_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rosidl_buffer_py_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rosidl_buffer_py_DIR}/${_extra}")
endforeach()
