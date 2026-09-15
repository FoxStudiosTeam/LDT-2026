# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rmw_security_common_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rmw_security_common_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rmw_security_common_FOUND FALSE)
  elseif(NOT rmw_security_common_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rmw_security_common_FOUND FALSE)
  endif()
  return()
endif()
set(_rmw_security_common_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rmw_security_common_FIND_QUIETLY)
  message(STATUS "Found rmw_security_common: 7.11.1 (${rmw_security_common_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rmw_security_common' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT rmw_security_common_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rmw_security_common_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake")
foreach(_extra ${_extras})
  include("${rmw_security_common_DIR}/${_extra}")
endforeach()
