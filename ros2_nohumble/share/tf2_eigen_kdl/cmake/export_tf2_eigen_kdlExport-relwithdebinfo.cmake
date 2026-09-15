#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tf2_eigen_kdl::tf2_eigen_kdl" for configuration "RelWithDebInfo"
set_property(TARGET tf2_eigen_kdl::tf2_eigen_kdl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tf2_eigen_kdl::tf2_eigen_kdl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/tf2_eigen_kdl.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/tf2_eigen_kdl.dll"
  )

list(APPEND _cmake_import_check_targets tf2_eigen_kdl::tf2_eigen_kdl )
list(APPEND _cmake_import_check_files_for_tf2_eigen_kdl::tf2_eigen_kdl "${_IMPORT_PREFIX}/lib/tf2_eigen_kdl.lib" "${_IMPORT_PREFIX}/bin/tf2_eigen_kdl.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
