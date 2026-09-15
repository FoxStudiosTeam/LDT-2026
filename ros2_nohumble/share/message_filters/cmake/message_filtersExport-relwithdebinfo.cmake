#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "message_filters::message_filters" for configuration "RelWithDebInfo"
set_property(TARGET message_filters::message_filters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(message_filters::message_filters PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/message_filters.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/message_filters.dll"
  )

list(APPEND _cmake_import_check_targets message_filters::message_filters )
list(APPEND _cmake_import_check_files_for_message_filters::message_filters "${_IMPORT_PREFIX}/lib/message_filters.lib" "${_IMPORT_PREFIX}/bin/message_filters.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
