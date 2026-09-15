#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rviz_common::rviz_common" for configuration "RelWithDebInfo"
set_property(TARGET rviz_common::rviz_common APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rviz_common::rviz_common PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rviz_common.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "resource_retriever::resource_retriever;tinyxml2::tinyxml2"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rviz_common.dll"
  )

list(APPEND _cmake_import_check_targets rviz_common::rviz_common )
list(APPEND _cmake_import_check_files_for_rviz_common::rviz_common "${_IMPORT_PREFIX}/lib/rviz_common.lib" "${_IMPORT_PREFIX}/bin/rviz_common.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
