#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iceoryx_posh::iceoryx_posh" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_posh::iceoryx_posh APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_posh::iceoryx_posh PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_posh.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_posh::iceoryx_posh )
list(APPEND _cmake_import_check_files_for_iceoryx_posh::iceoryx_posh "${_IMPORT_PREFIX}/lib/iceoryx_posh.lib" )

# Import target "iceoryx_posh::iceoryx_posh_roudi" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_posh::iceoryx_posh_roudi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_posh::iceoryx_posh_roudi PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_posh_roudi.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_posh::iceoryx_posh_roudi )
list(APPEND _cmake_import_check_files_for_iceoryx_posh::iceoryx_posh_roudi "${_IMPORT_PREFIX}/lib/iceoryx_posh_roudi.lib" )

# Import target "iceoryx_posh::iceoryx_posh_gateway" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_posh::iceoryx_posh_gateway APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_posh::iceoryx_posh_gateway PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_posh_gateway.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_posh::iceoryx_posh_gateway )
list(APPEND _cmake_import_check_files_for_iceoryx_posh::iceoryx_posh_gateway "${_IMPORT_PREFIX}/lib/iceoryx_posh_gateway.lib" )

# Import target "iceoryx_posh::iceoryx_posh_config" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_posh::iceoryx_posh_config APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_posh::iceoryx_posh_config PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/iceoryx_posh_config.lib"
  )

list(APPEND _cmake_import_check_targets iceoryx_posh::iceoryx_posh_config )
list(APPEND _cmake_import_check_files_for_iceoryx_posh::iceoryx_posh_config "${_IMPORT_PREFIX}/lib/iceoryx_posh_config.lib" )

# Import target "iceoryx_posh::iox-roudi" for configuration "RelWithDebInfo"
set_property(TARGET iceoryx_posh::iox-roudi APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iceoryx_posh::iox-roudi PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/iox-roudi.exe"
  )

list(APPEND _cmake_import_check_targets iceoryx_posh::iox-roudi )
list(APPEND _cmake_import_check_files_for_iceoryx_posh::iox-roudi "${_IMPORT_PREFIX}/bin/iox-roudi.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
