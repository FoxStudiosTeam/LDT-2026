#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosbag2_compression::rosbag2_compression" for configuration "RelWithDebInfo"
set_property(TARGET rosbag2_compression::rosbag2_compression APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosbag2_compression::rosbag2_compression PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosbag2_compression.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosbag2_compression.dll"
  )

list(APPEND _cmake_import_check_targets rosbag2_compression::rosbag2_compression )
list(APPEND _cmake_import_check_files_for_rosbag2_compression::rosbag2_compression "${_IMPORT_PREFIX}/lib/rosbag2_compression.lib" "${_IMPORT_PREFIX}/bin/rosbag2_compression.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
