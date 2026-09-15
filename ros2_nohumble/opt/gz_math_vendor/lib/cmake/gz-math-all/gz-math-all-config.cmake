# - Config to retrieve all components of the gz-math package
#
# This should only be invoked by gz-math-config.cmake.
#
# To retrieve this meta-package, use:
# find_package(gz-math COMPONENTS all)
#
# This creates the target gz-math::all which will link to all known
# components of gz-math, including the core library.
#
# This also creates the variable gz-math_ALL_LIBRARIES
#
################################################################################

cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

if(gz-math_ALL_CONFIG_INCLUDED)
  return()
endif()
set(gz-math_ALL_CONFIG_INCLUDED TRUE)

if(NOT gz-math-all_FIND_QUIETLY)
  message(STATUS "Looking for all libraries of gz-math -- found version 9.2.0")
endif()


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was gz-all-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# Get access to the find_dependency utility
include(CMakeFindDependencyMacro)

# Find the core library
find_dependency(gz-math 9.2.0 EXACT)

# Find the component libraries
find_dependency(gz-math-eigen3 9.2.0 EXACT)

if(NOT TARGET gz-math::gz-math-all)
  include("${CMAKE_CURRENT_LIST_DIR}/gz-math-all-targets.cmake")

  add_library(gz-math::all INTERFACE IMPORTED)
  set_target_properties(gz-math::all PROPERTIES
    INTERFACE_LINK_LIBRARIES "gz-math::gz-math-all")

endif()

# Create the "requested" target if it does not already exist
if(NOT TARGET gz-math::requested)
  add_library(gz-math::requested INTERFACE IMPORTED)
endif()

# Link the "all" target to the "requested" target
get_target_property(gz_requested_components gz-math::requested INTERFACE_LINK_LIBRARIES)
if(NOT gz_requested_components)
  set_target_properties(gz-math::requested PROPERTIES
    INTERFACE_LINK_LIBRARIES "gz-math::gz-math-all")
else()
  set_target_properties(gz-math::requested PROPERTIES
    INTERFACE_LINK_LIBRARIES "${gz_requested_components};gz-math::gz-math-all")
endif()

set(gz-math_ALL_LIBRARIES gz-math::gz-math-all)
