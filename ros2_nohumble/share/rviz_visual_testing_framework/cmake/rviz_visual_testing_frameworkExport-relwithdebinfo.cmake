#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rviz_visual_testing_framework::rviz_visual_testing_framework" for configuration "RelWithDebInfo"
set_property(TARGET rviz_visual_testing_framework::rviz_visual_testing_framework APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rviz_visual_testing_framework::rviz_visual_testing_framework PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rviz_visual_testing_framework.lib"
  )

list(APPEND _cmake_import_check_targets rviz_visual_testing_framework::rviz_visual_testing_framework )
list(APPEND _cmake_import_check_files_for_rviz_visual_testing_framework::rviz_visual_testing_framework "${_IMPORT_PREFIX}/lib/rviz_visual_testing_framework.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
