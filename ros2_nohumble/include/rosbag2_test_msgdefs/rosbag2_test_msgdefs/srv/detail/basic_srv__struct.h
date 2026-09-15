// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:srv\BasicSrv.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/srv/basic_srv.h"


#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__BASIC_SRV__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__BASIC_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'req'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BasicSrv in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Request
{
  rosidl_runtime_c__String req;
} rosbag2_test_msgdefs__srv__BasicSrv_Request;

// Struct for a sequence of rosbag2_test_msgdefs__srv__BasicSrv_Request.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence
{
  rosbag2_test_msgdefs__srv__BasicSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'resp'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BasicSrv in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Response
{
  rosidl_runtime_c__String resp;
} rosbag2_test_msgdefs__srv__BasicSrv_Response;

// Struct for a sequence of rosbag2_test_msgdefs__srv__BasicSrv_Response.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence
{
  rosbag2_test_msgdefs__srv__BasicSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_test_msgdefs__srv__BasicSrv_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_test_msgdefs__srv__BasicSrv_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/BasicSrv in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_test_msgdefs__srv__BasicSrv_Request__Sequence request;
  rosbag2_test_msgdefs__srv__BasicSrv_Response__Sequence response;
} rosbag2_test_msgdefs__srv__BasicSrv_Event;

// Struct for a sequence of rosbag2_test_msgdefs__srv__BasicSrv_Event.
typedef struct rosbag2_test_msgdefs__srv__BasicSrv_Event__Sequence
{
  rosbag2_test_msgdefs__srv__BasicSrv_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__BasicSrv_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__BASIC_SRV__STRUCT_H_
