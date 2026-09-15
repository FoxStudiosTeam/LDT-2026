// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_test_msgdefs:srv\ComplexSrvIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/srv/complex_srv_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__TRAITS_HPP_
#define ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_test_msgdefs/srv/detail/complex_srv_idl__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'req'
#include "rosbag2_test_msgdefs/msg/detail/basic_idl__traits.hpp"

namespace rosbag2_test_msgdefs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComplexSrvIdl_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: req
  {
    out << "req: ";
    to_flow_style_yaml(msg.req, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexSrvIdl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "req:\n";
    to_block_style_yaml(msg.req, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexSrvIdl_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).req);
}

}  // namespace srv

}  // namespace rosbag2_test_msgdefs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>()
{
  return "rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>()
{
  return "rosbag2_test_msgdefs/srv/ComplexSrvIdl_Request";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>
  : std::integral_constant<bool, has_fixed_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>
  : std::integral_constant<bool, has_bounded_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct is_message<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "req",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'resp'
// already included above
// #include "rosbag2_test_msgdefs/msg/detail/basic_idl__traits.hpp"

namespace rosbag2_test_msgdefs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComplexSrvIdl_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: resp
  {
    out << "resp: ";
    to_flow_style_yaml(msg.resp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexSrvIdl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: resp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resp:\n";
    to_block_style_yaml(msg.resp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexSrvIdl_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).resp);
}

}  // namespace srv

}  // namespace rosbag2_test_msgdefs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>()
{
  return "rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>()
{
  return "rosbag2_test_msgdefs/srv/ComplexSrvIdl_Response";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>
  : std::integral_constant<bool, has_fixed_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>
  : std::integral_constant<bool, has_bounded_size<rosbag2_test_msgdefs::msg::BasicIdl>::value> {};

template<>
struct is_message<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "resp",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace rosbag2_test_msgdefs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComplexSrvIdl_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexSrvIdl_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexSrvIdl_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace rosbag2_test_msgdefs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>()
{
  return "rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>()
{
  return "rosbag2_test_msgdefs/srv/ComplexSrvIdl_Event";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>
  : std::integral_constant<bool, has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>::value && has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Event>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "info",
    "request",
    "response",
  };
};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_test_msgdefs::srv::ComplexSrvIdl>()
{
  return "rosbag2_test_msgdefs::srv::ComplexSrvIdl";
}

template<>
constexpr const char * name<rosbag2_test_msgdefs::srv::ComplexSrvIdl>()
{
  return "rosbag2_test_msgdefs/srv/ComplexSrvIdl";
}

template<>
struct has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl>
  : std::integral_constant<
    bool,
    has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>::value &&
    has_fixed_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>::value
  >
{
};

template<>
struct has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl>
  : std::integral_constant<
    bool,
    has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>::value &&
    has_bounded_size<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>::value
  >
{
};

template<>
struct is_service<rosbag2_test_msgdefs::srv::ComplexSrvIdl>
  : std::true_type
{
};

template<>
struct is_service_request<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rosbag2_test_msgdefs::srv::ComplexSrvIdl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_TEST_MSGDEFS__SRV__DETAIL__COMPLEX_SRV_IDL__TRAITS_HPP_
