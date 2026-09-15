// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rosbag2_test_msgdefs:action\BasicMsg.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__BASIC_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__BASIC_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_Goal & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_Goal & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_Goal & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_Goal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Goal & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Goal & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_Goal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_Goal();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_Goal)();

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_Result & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_Result & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_Result & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_Result(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Result & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Result & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_Result(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_Result();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_Result)();

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_Feedback & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_Feedback & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_Feedback & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_Feedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Feedback & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_Feedback & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_Feedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_Feedback();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_Feedback)();

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_SendGoal_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Request & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_SendGoal_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_SendGoal_Request();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_SendGoal_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_SendGoal_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Response & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_SendGoal_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_SendGoal_Response();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_SendGoal_Response)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Event & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_SendGoal_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Event & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_SendGoal_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_SendGoal_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_SendGoal_Event();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_SendGoal_Event)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_SendGoal)();

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_GetResult_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_GetResult_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Request & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_GetResult_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_GetResult_Request();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_GetResult_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_GetResult_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_GetResult_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Response & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_GetResult_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_GetResult_Response();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_GetResult_Response)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_GetResult_Event & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_GetResult_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Event & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_GetResult_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_GetResult_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_GetResult_Event();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_GetResult_Event)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rmw/types.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_GetResult)();

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosbag2_test_msgdefs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "rosbag2_test_msgdefs/action/detail/basic_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace rosbag2_test_msgdefs
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize(
  const rosbag2_test_msgdefs::action::BasicMsg_FeedbackMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs::action::BasicMsg_FeedbackMessage & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size(
  const rosbag2_test_msgdefs::action::BasicMsg_FeedbackMessage & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_BasicMsg_FeedbackMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
cdr_serialize_key(
  const rosbag2_test_msgdefs::action::BasicMsg_FeedbackMessage & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
get_serialized_size_key(
  const rosbag2_test_msgdefs::action::BasicMsg_FeedbackMessage & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
max_serialized_size_key_BasicMsg_FeedbackMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
has_buffer_fields_BasicMsg_FeedbackMessage();

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace rosbag2_test_msgdefs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rosbag2_test_msgdefs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rosbag2_test_msgdefs, action, BasicMsg_FeedbackMessage)();

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__ACTION__DETAIL__BASIC_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
