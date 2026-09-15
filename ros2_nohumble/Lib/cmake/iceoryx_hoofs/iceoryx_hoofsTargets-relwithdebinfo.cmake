#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iceoryx_hoofs::iceoryx_hoofs" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_hoofs::iceoryx_hoofs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_hoofs::iceoryx_hoofs PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_hoofs.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_hoofs::iceoryx_hoofs )
list(APPEND _cmake_import_check_files_for_iceoryx_hoofs::iceoryx_hoofs "${_IMPORT_PREFIX}/lib/iceoryx_hoofs.lib" )

# Import target "iceoryx_hoofs::iceoryx_platform" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_hoofs::iceoryx_platform APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_hoofs::iceoryx_platform PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_platform.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_hoofs::iceoryx_platform )
list(APPEND _cmake_import_check_files_for_iceoryx_hoofs::iceoryx_platform "${_IMPORT_PREFIX}/lib/iceoryx_platform.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
