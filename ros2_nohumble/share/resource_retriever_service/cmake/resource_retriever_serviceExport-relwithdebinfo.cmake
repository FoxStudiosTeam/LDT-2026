#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "resource_retriever_service::resource_retriever_service" for configuration "RelWithDebInfo"
set_property(TARGET resource_retriever_service::resource_retriever_service APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(resource_retriever_service::resource_retriever_service PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/resource_retriever_service.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/resource_retriever_service.dll"
  )

list(APPEND _cmake_import_check_targets resource_retriever_service::resource_retriever_service )
list(APPEND _cmake_import_check_files_for_resource_retriever_service::resource_retriever_service "${_IMPORT_PREFIX}/lib/resource_retriever_service.lib" "${_IMPORT_PREFIX}/bin/resource_retriever_service.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
