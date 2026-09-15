
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was urdfdom-config.cmake.in                            ########

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

if (urdfdom_CONFIG_INCLUDED)
  return()
endif()
set(urdfdom_CONFIG_INCLUDED TRUE)

set(CMAKE_MODULE_PATH_BACKUP_URDFDOM ${CMAKE_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH "${urdfdom_DIR}")

set(urdfdom_INCLUDE_DIRS "${urdfdom_DIR}/../../../include/urdfdom")

foreach(lib urdfdom_sensor;urdfdom_model;urdfdom_world)
  set(onelib "${lib}-NOTFOUND")
  set(onelibd "${lib}-NOTFOUND")
  find_library(onelib ${lib}
    PATHS "${urdfdom_DIR}/../../../lib"
    NO_DEFAULT_PATH)
  find_library(onelibd ${lib}d
    PATHS "${urdfdom_DIR}/../../../lib"
    NO_DEFAULT_PATH)
  if(onelib-NOTFOUND AND onelibd-NOTFOUND)
    message(FATAL_ERROR "Library '${lib}' in package urdfdom is not installed properly")
  endif()
  if(onelib AND onelibd)
    list(APPEND urdfdom_LIBRARIES $<$<NOT:$<CONFIG:Debug>>:${onelib}>)
    list(APPEND urdfdom_LIBRARIES $<$<CONFIG:Debug>:${onelibd}>)
  else()
    if(onelib)
      list(APPEND urdfdom_LIBRARIES ${onelib})
    else()
      list(APPEND urdfdom_LIBRARIES ${onelibd})
    endif()
  endif()
  list(APPEND urdfdom_TARGETS urdfdom::${lib})
endforeach()

foreach(dep urdfdom_headers)
  if(NOT ${dep}_FOUND)
    find_package(${dep})
  endif()
  list(APPEND urdfdom_INCLUDE_DIRS ${${dep}_INCLUDE_DIRS})
  list(APPEND urdfdom_LIBRARIES ${${dep}_LIBRARIES})
endforeach()

foreach(exp urdfdom)
  include(${urdfdom_DIR}/${exp}Export.cmake)
endforeach()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH_BACKUP_URDFDOM})
