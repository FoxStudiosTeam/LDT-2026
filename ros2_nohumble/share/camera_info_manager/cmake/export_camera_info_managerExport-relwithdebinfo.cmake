#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "camera_info_manager::camera_info_manager" for configuration "RelWithDebInfo"
set_property(TARGET camera_info_manager::camera_info_manager APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(camera_info_manager::camera_info_manager PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/camera_info_manager.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp;camera_calibration_parsers::camera_calibration_parsers;rcpputils::rcpputils"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/camera_info_manager.dll"
  )

list(APPEND _cmake_import_check_targets camera_info_manager::camera_info_manager )
list(APPEND _cmake_import_check_files_for_camera_info_manager::camera_info_manager "${_IMPORT_PREFIX}/lib/camera_info_manager.lib" "${_IMPORT_PREFIX}/bin/camera_info_manager.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
