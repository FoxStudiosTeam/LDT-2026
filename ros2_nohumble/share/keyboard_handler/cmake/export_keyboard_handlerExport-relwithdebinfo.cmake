#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "keyboard_handler::keyboard_handler" for configuration "RelWithDebInfo"
set_property(TARGET keyboard_handler::keyboard_handler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(keyboard_handler::keyboard_handler PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/keyboard_handler.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/keyboard_handler.dll"
  )

list(APPEND _cmake_import_check_targets keyboard_handler::keyboard_handler )
list(APPEND _cmake_import_check_files_for_keyboard_handler::keyboard_handler "${_IMPORT_PREFIX}/lib/keyboard_handler.lib" "${_IMPORT_PREFIX}/bin/keyboard_handler.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
