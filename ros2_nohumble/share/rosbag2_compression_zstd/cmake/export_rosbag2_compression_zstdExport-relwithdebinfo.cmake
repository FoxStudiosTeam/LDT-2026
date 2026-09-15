#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosbag2_compression_zstd::rosbag2_compression_zstd" for configuration "RelWithDebInfo"
set_property(TARGET rosbag2_compression_zstd::rosbag2_compression_zstd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosbag2_compression_zstd::rosbag2_compression_zstd PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosbag2_compression_zstd.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosbag2_compression_zstd.dll"
  )

list(APPEND _cmake_import_check_targets rosbag2_compression_zstd::rosbag2_compression_zstd )
list(APPEND _cmake_import_check_files_for_rosbag2_compression_zstd::rosbag2_compression_zstd "${_IMPORT_PREFIX}/lib/rosbag2_compression_zstd.lib" "${_IMPORT_PREFIX}/bin/rosbag2_compression_zstd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
