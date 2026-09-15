// generated from
// rosidl_typesupport_fastrtps_c/resource/rosidl_typesupport_fastrtps_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef TEST_ROSIDL_BUFFER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
#define TEST_ROSIDL_BUFFER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_test_rosidl_buffer __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_test_rosidl_buffer __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_test_rosidl_buffer __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_test_rosidl_buffer __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_C_BUILDING_DLL_test_rosidl_buffer
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_test_rosidl_buffer
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_test_rosidl_buffer
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_EXPORT_test_rosidl_buffer __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_test_rosidl_buffer
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_test_rosidl_buffer
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // TEST_ROSIDL_BUFFER__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_C__VISIBILITY_CONTROL_H_
