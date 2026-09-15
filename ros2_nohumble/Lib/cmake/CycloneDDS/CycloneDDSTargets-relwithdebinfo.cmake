#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CycloneDDS::libidlc" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::libidlc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::libidlc PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/cycloneddsidlc.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "CycloneDDS::idl;CycloneDDS::ddsc"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/cycloneddsidlc.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::libidlc )
list(APPEND _cmake_import_check_files_for_CycloneDDS::libidlc "${_IMPORT_PREFIX}/lib/cycloneddsidlc.lib" "${_IMPORT_PREFIX}/bin/cycloneddsidlc.dll" )

# Import target "CycloneDDS::idlc" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::idlc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::idlc PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/idlc.exe"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::idlc )
list(APPEND _cmake_import_check_files_for_CycloneDDS::idlc "${_IMPORT_PREFIX}/bin/idlc.exe" )

# Import target "CycloneDDS::idl" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::idl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::idl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/cycloneddsidl.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/cycloneddsidl.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::idl )
list(APPEND _cmake_import_check_files_for_CycloneDDS::idl "${_IMPORT_PREFIX}/lib/cycloneddsidl.lib" "${_IMPORT_PREFIX}/bin/cycloneddsidl.dll" )

# Import target "CycloneDDS::dds_security_ac" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::dds_security_ac APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::dds_security_ac PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/dds_security_ac.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/dds_security_ac.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::dds_security_ac )
list(APPEND _cmake_import_check_files_for_CycloneDDS::dds_security_ac "${_IMPORT_PREFIX}/lib/dds_security_ac.lib" "${_IMPORT_PREFIX}/bin/dds_security_ac.dll" )

# Import target "CycloneDDS::dds_security_auth" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::dds_security_auth APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::dds_security_auth PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/dds_security_auth.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/dds_security_auth.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::dds_security_auth )
list(APPEND _cmake_import_check_files_for_CycloneDDS::dds_security_auth "${_IMPORT_PREFIX}/lib/dds_security_auth.lib" "${_IMPORT_PREFIX}/bin/dds_security_auth.dll" )

# Import target "CycloneDDS::dds_security_crypto" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::dds_security_crypto APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::dds_security_crypto PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/dds_security_crypto.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/dds_security_crypto.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::dds_security_crypto )
list(APPEND _cmake_import_check_files_for_CycloneDDS::dds_security_crypto "${_IMPORT_PREFIX}/lib/dds_security_crypto.lib" "${_IMPORT_PREFIX}/bin/dds_security_crypto.dll" )

# Import target "CycloneDDS::psmx_iox" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::psmx_iox APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::psmx_iox PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/psmx_iox.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "CycloneDDS::ddsc"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/psmx_iox.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::psmx_iox )
list(APPEND _cmake_import_check_files_for_CycloneDDS::psmx_iox "${_IMPORT_PREFIX}/lib/psmx_iox.lib" "${_IMPORT_PREFIX}/bin/psmx_iox.dll" )

# Import target "CycloneDDS::ddsc" for configuration "RelWithDebInfo"
set_property(TARGET CycloneDDS::ddsc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CycloneDDS::ddsc PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/ddsc.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/ddsc.dll"
  )

list(APPEND _cmake_import_check_targets CycloneDDS::ddsc )
list(APPEND _cmake_import_check_files_for_CycloneDDS::ddsc "${_IMPORT_PREFIX}/lib/ddsc.lib" "${_IMPORT_PREFIX}/bin/ddsc.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
