#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iceoryx_binding_c::iceoryx_binding_c" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_binding_c::iceoryx_binding_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_binding_c::iceoryx_binding_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_binding_c.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_binding_c::iceoryx_binding_c )
list(APPEND _cmake_import_check_files_for_iceoryx_binding_c::iceoryx_binding_c "${_IMPORT_PREFIX}/lib/iceoryx_binding_c.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
