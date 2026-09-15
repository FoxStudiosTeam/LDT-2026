// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_msgs:srv\TeleportRelative.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/srv/teleport_relative.hpp"


#ifndef TURTLESIM_MSGS__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_
#define TURTLESIM_MSGS__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "turtlesim_msgs/srv/detail/teleport_relative__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlesim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeleportRelative_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear
  {
    out << "linear: ";
    rosidl_generator_traits::value_to_yaml(msg.linear, out);
    out << ", ";
  }

  // member: angular
  {
    out << "angular: ";
    rosidl_generator_traits::value_to_yaml(msg.angular, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeleportRelative_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear: ";
    rosidl_generator_traits::value_to_yaml(msg.linear, out);
    out << "\n";
  }

  // member: angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular: ";
    rosidl_generator_traits::value_to_yaml(msg.angular, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeleportRelative_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::TeleportRelative_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).linear,
    std::forward<T>(msg).angular);
}

}  // namespace srv

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::srv::TeleportRelative_Request>()
{
  return "turtlesim_msgs::srv::TeleportRelative_Request";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::TeleportRelative_Request>()
{
  return "turtlesim_msgs/srv/TeleportRelative_Request";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::TeleportRelative_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::srv::TeleportRelative_Request>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::TeleportRelative_Request>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "linear",
    "angular",
  };
};

}  // namespace rosidl_generator_traits

namespace turtlesim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeleportRelative_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeleportRelative_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeleportRelative_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::TeleportRelative_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace srv

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::srv::TeleportRelative_Response>()
{
  return "turtlesim_msgs::srv::TeleportRelative_Response";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::TeleportRelative_Response>()
{
  return "turtlesim_msgs/srv/TeleportRelative_Response";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::TeleportRelative_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::srv::TeleportRelative_Response>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::TeleportRelative_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "structure_needs_at_least_one_member",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace turtlesim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeleportRelative_Event & msg,
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
  const TeleportRelative_Event & msg,
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

inline std::string to_yaml(const TeleportRelative_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::TeleportRelative_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::srv::TeleportRelative_Event>()
{
  return "turtlesim_msgs::srv::TeleportRelative_Event";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::TeleportRelative_Event>()
{
  return "turtlesim_msgs/srv/TeleportRelative_Event";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::TeleportRelative_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Request>::value && has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Response>::value> {};

template<>
struct is_message<turtlesim_msgs::srv::TeleportRelative_Event>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::TeleportRelative_Event>
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
constexpr const char * data_type<turtlesim_msgs::srv::TeleportRelative>()
{
  return "turtlesim_msgs::srv::TeleportRelative";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::TeleportRelative>()
{
  return "turtlesim_msgs/srv/TeleportRelative";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::TeleportRelative>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim_msgs::srv::TeleportRelative_Request>::value &&
    has_fixed_size<turtlesim_msgs::srv::TeleportRelative_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim_msgs::srv::TeleportRelative>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Request>::value &&
    has_bounded_size<turtlesim_msgs::srv::TeleportRelative_Response>::value
  >
{
};

template<>
struct is_service<turtlesim_msgs::srv::TeleportRelative>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim_msgs::srv::TeleportRelative_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim_msgs::srv::TeleportRelative_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_MSGS__SRV__DETAIL__TELEPORT_RELATIVE__TRAITS_HPP_
