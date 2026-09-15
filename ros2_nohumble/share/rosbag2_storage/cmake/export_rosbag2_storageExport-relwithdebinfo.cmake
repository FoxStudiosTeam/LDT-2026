#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosbag2_storage::rosbag2_storage" for configuration "RelWithDebInfo"
set_property(TARGET rosbag2_storage::rosbag2_storage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosbag2_storage::rosbag2_storage PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosbag2_storage.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosbag2_storage.dll"
  )

list(APPEND _cmake_import_check_targets rosbag2_storage::rosbag2_storage )
list(APPEND _cmake_import_check_files_for_rosbag2_storage::rosbag2_storage "${_IMPORT_PREFIX}/lib/rosbag2_storage.lib" "${_IMPORT_PREFIX}/bin/rosbag2_storage.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
