#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_py" for configuration "RelWithDebInfo"
set_property(TARGET test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_py PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/test_rosidl_buffer__rosidl_generator_py.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_c;Python3::Python;test_rosidl_buffer::test_rosidl_buffer__rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/test_rosidl_buffer__rosidl_generator_py.dll"
  )

list(APPEND _cmake_import_check_targets test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_test_rosidl_buffer::test_rosidl_buffer__rosidl_generator_py "${_IMPORT_PREFIX}/lib/test_rosidl_buffer__rosidl_generator_py.lib" "${_IMPORT_PREFIX}/bin/test_rosidl_buffer__rosidl_generator_py.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
