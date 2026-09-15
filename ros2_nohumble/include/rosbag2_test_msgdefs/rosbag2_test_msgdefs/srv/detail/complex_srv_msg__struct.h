// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/srv/complex_srv_msg.h"


#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_H_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_H_

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
#include "rosbag2_test_msgdefs/msg/detail/basic_msg__struct.h"

/// Struct defined in srv/ComplexSrvMsg in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request
{
  rosbag2_test_msgdefs__msg__BasicMsg req;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request;

// Struct for a sequence of rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence
{
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'resp'
// already included above
// #include "rosbag2_test_msgdefs/msg/detail/basic_msg__struct.h"

/// Struct defined in srv/ComplexSrvMsg in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response
{
  rosbag2_test_msgdefs__msg__BasicMsg resp;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response;

// Struct for a sequence of rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence
{
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ComplexSrvMsg in the package rosbag2_test_msgdefs.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Request__Sequence request;
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Response__Sequence response;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event;

// Struct for a sequence of rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event.
typedef struct rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__Sequence
{
  rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_test_msgdefs__srv__ComplexSrvMsg_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_MSG__STRUCT_H_
