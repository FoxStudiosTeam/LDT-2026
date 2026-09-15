// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c_impl.hpp.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__struct.h"
#include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__functions.h"
#include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__rosidl_typesupport_fastrtps_c.h"
#include "fastcdr/Cdr.h"

#include "rosbag2_test_msgdefs/msg/detail/basic_idl__functions.h"  // req

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "rosbag2_test_msgdefs/msg/detail/basic_idl__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ComplexSrvIdl_Request__ros_msg_type = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request;


inline
bool impl_cdr_serialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: req
  {
    impl_cdr_serialize_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->req, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request * ros_message)
{
  // Field name: req
  {
    impl_cdr_deserialize_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->req);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Request__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: req
  current_alignment += impl_get_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->req), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: req
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request;
    is_plain =
      (
      offsetof(DataType, req) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: req
  {
    impl_cdr_serialize_key_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->req, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Request__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: req
  current_alignment += impl_get_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->req), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: req
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request;
    is_plain =
      (
      offsetof(DataType, req) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: req
  {
    impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->req, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: req
  {
    impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->req, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include <vector>
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__struct.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__functions.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__rosidl_typesupport_fastrtps_c.h"
// already included above
// #include "fastcdr/Cdr.h"

// already included above
// #include "rosbag2_test_msgdefs/msg/detail/basic_idl__functions.h"  // resp

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
// already included above
// #include "rosbag2_test_msgdefs/msg/detail/basic_idl__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ComplexSrvIdl_Response__ros_msg_type = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response;


inline
bool impl_cdr_serialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: resp
  {
    impl_cdr_serialize_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->resp, cdr);
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response * ros_message)
{
  // Field name: resp
  {
    impl_cdr_deserialize_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->resp);
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Response__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: resp
  current_alignment += impl_get_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->resp), current_alignment);

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: resp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response;
    is_plain =
      (
      offsetof(DataType, resp) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: resp
  {
    impl_cdr_serialize_key_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->resp, cdr);
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Response__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: resp
  current_alignment += impl_get_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
    &(ros_message->resp), current_alignment);

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: resp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosbag2_test_msgdefs__msg__BasicIdl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response;
    is_plain =
      (
      offsetof(DataType, resp) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: resp
  {
    impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(
      &ros_message->resp, cdr, endpoint_info, serialization_context);
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: resp
  {
    impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__msg__BasicIdl(cdr, &ros_message->resp, endpoint_info, serialization_context);
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include <vector>
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__struct.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__functions.h"
// already included above
// #include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__rosidl_typesupport_fastrtps_c.h"
// already included above
// #include "fastcdr/Cdr.h"

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// Include the inline (de)serialization headers of nested message types so
// their bodies are visible here and can be fully inlined by the compiler.
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_fastrtps_c_impl.hpp"

#if defined(__cplusplus)
extern "C"
{
#endif

using _ComplexSrvIdl_Event__ros_msg_type = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event;


inline
bool impl_cdr_serialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    impl_cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event * ros_message)
{
  // Field name: info
  {
    impl_cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__fini(&ros_message->request);
    }
    if (!rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__fini(&ros_message->response);
    }
    if (!rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


inline
size_t impl_get_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Event__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += impl_get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


inline
size_t impl_max_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    impl_cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

inline
size_t impl_get_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ComplexSrvIdl_Event__ros_msg_type * ros_message = static_cast<const _ComplexSrvIdl_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += impl_get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += impl_get_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

inline
size_t impl_max_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        impl_max_serialized_size_key_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

inline
bool impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  const rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    impl_cdr_serialize_with_endpoint_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr, endpoint_info, serialization_context);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_serialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

inline
bool impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event(
  eprosima::fastcdr::Cdr & cdr,
  rosbag2_test_msgdefs__srv__ComplexSrvIdl_Event * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    impl_cdr_deserialize_with_endpoint_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info, endpoint_info, serialization_context);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__fini(&ros_message->request);
    }
    if (!rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Request(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__fini(&ros_message->response);
    }
    if (!rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      impl_cdr_deserialize_with_endpoint_rosbag2_test_msgdefs__srv__ComplexSrvIdl_Response(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

#if defined(__cplusplus)
}
#endif

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPL_HPP_
