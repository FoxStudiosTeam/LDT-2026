# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_mimick_vendor_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED mimick_vendor_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(mimick_vendor_FOUND FALSE)
  elseif(NOT mimick_vendor_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(mimick_vendor_FOUND FALSE)
  endif()
  return()
endif()
set(_mimick_vendor_CONFIG_INCLUDED TRUE)

# output package information
if(NOT mimick_vendor_FIND_QUIETLY)
  message(STATUS "Found mimick_vendor: 0.10.0 (${mimick_vendor_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'mimick_vendor' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT mimick_vendor_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(mimick_vendor_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "vendor_package_cmake_prefix.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${mimick_vendor_DIR}/${_extra}")
endforeach()
