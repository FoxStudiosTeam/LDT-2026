# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rmw_connextddsmicro_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rmw_connextddsmicro_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rmw_connextddsmicro_FOUND FALSE)
  elseif(NOT rmw_connextddsmicro_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rmw_connextddsmicro_FOUND FALSE)
  endif()
  return()
endif()
set(_rmw_connextddsmicro_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rmw_connextddsmicro_FIND_QUIETLY)
  message(STATUS "Found rmw_connextddsmicro: 1.3.0 (${rmw_connextddsmicro_DIR})")
endif()

# warn when using a deprecated package
if(NOT "This package will be removed in a future ROS 2 distro. Use rmw_connextdds instead." STREQUAL "")
  set(_msg "Package 'rmw_connextddsmicro' is deprecated")
  # append custom deprecation text if available
  if(NOT "This package will be removed in a future ROS 2 distro. Use rmw_connextdds instead." STREQUAL "TRUE")
    set(_msg "${_msg} (This package will be removed in a future ROS 2 distro. Use rmw_connextdds instead.)")
  endif()
  # optionally quiet the deprecation message
  if(NOT rmw_connextddsmicro_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rmw_connextddsmicro_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rmw_connextddsmicro_DIR}/${_extra}")
endforeach()
