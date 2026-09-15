#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "point_cloud_transport::point_cloud_transport" for configuration "RelWithDebInfo"
set_property(TARGET point_cloud_transport::point_cloud_transport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(point_cloud_transport::point_cloud_transport PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/point_cloud_transport.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "tinyxml2::tinyxml2"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/point_cloud_transport.dll"
  )

list(APPEND _cmake_import_check_targets point_cloud_transport::point_cloud_transport )
list(APPEND _cmake_import_check_files_for_point_cloud_transport::point_cloud_transport "${_IMPORT_PREFIX}/lib/point_cloud_transport.lib" "${_IMPORT_PREFIX}/bin/point_cloud_transport.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
