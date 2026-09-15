#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "image_tools::image_tools" for configuration "RelWithDebInfo"
set_property(TARGET image_tools::image_tools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(image_tools::image_tools PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/image_tools.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/image_tools.dll"
  )

list(APPEND _cmake_import_check_targets image_tools::image_tools )
list(APPEND _cmake_import_check_files_for_image_tools::image_tools "${_IMPORT_PREFIX}/lib/image_tools.lib" "${_IMPORT_PREFIX}/bin/image_tools.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
