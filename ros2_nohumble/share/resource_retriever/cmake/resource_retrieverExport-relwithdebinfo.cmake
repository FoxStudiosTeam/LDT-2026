#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "resource_retriever::resource_retriever" for configuration "RelWithDebInfo"
set_property(TARGET resource_retriever::resource_retriever APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(resource_retriever::resource_retriever PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/resource_retriever.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "ament_index_cpp::ament_index_cpp"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/resource_retriever.dll"
  )

list(APPEND _cmake_import_check_targets resource_retriever::resource_retriever )
list(APPEND _cmake_import_check_files_for_resource_retriever::resource_retriever "${_IMPORT_PREFIX}/lib/resource_retriever.lib" "${_IMPORT_PREFIX}/bin/resource_retriever.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
