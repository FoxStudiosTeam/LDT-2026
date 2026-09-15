#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "image_transport::image_transport" for configuration "RelWithDebInfo"
set_property(TARGET image_transport::image_transport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(image_transport::image_transport PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/image_transport.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "tinyxml2::tinyxml2"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/image_transport.dll"
  )

list(APPEND _cmake_import_check_targets image_transport::image_transport )
list(APPEND _cmake_import_check_files_for_image_transport::image_transport "${_IMPORT_PREFIX}/lib/image_transport.lib" "${_IMPORT_PREFIX}/bin/image_transport.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
