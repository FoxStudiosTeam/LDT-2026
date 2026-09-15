// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_msgs:srv\SetPen.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/srv/set_pen.hpp"


#ifndef TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__TRAITS_HPP_
#define TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "turtlesim_msgs/srv/detail/set_pen__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlesim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPen_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: r
  {
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << ", ";
  }

  // member: g
  {
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: off
  {
    out << "off: ";
    rosidl_generator_traits::value_to_yaml(msg.off, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPen_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r: ";
    rosidl_generator_traits::value_to_yaml(msg.r, out);
    out << "\n";
  }

  // member: g
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "g: ";
    rosidl_generator_traits::value_to_yaml(msg.g, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: off
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "off: ";
    rosidl_generator_traits::value_to_yaml(msg.off, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPen_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::SetPen_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).r,
    std::forward<T>(msg).g,
    std::forward<T>(msg).b,
    std::forward<T>(msg).width,
    std::forward<T>(msg).off);
}

}  // namespace srv

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::srv::SetPen_Request>()
{
  return "turtlesim_msgs::srv::SetPen_Request";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::SetPen_Request>()
{
  return "turtlesim_msgs/srv/SetPen_Request";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::SetPen_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::SetPen_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::srv::SetPen_Request>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::SetPen_Request>
{
  static constexpr std::size_t member_count = 5;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "r",
    "g",
    "b",
    "width",
    "off",
  };
};

}  // namespace rosidl_generator_traits

namespace turtlesim_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPen_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPen_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPen_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::SetPen_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace srv

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::srv::SetPen_Response>()
{
  return "turtlesim_msgs::srv::SetPen_Response";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::SetPen_Response>()
{
  return "turtlesim_msgs/srv/SetPen_Response";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::SetPen_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::SetPen_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::srv::SetPen_Response>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::SetPen_Response>
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
  const SetPen_Event & msg,
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
  const SetPen_Event & msg,
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

inline std::string to_yaml(const SetPen_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::srv::SetPen_Event>, int> = 0>
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
constexpr const char * data_type<turtlesim_msgs::srv::SetPen_Event>()
{
  return "turtlesim_msgs::srv::SetPen_Event";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::SetPen_Event>()
{
  return "turtlesim_msgs/srv/SetPen_Event";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::SetPen_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_msgs::srv::SetPen_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtlesim_msgs::srv::SetPen_Request>::value && has_bounded_size<turtlesim_msgs::srv::SetPen_Response>::value> {};

template<>
struct is_message<turtlesim_msgs::srv::SetPen_Event>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::srv::SetPen_Event>
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
constexpr const char * data_type<turtlesim_msgs::srv::SetPen>()
{
  return "turtlesim_msgs::srv::SetPen";
}

template<>
constexpr const char * name<turtlesim_msgs::srv::SetPen>()
{
  return "turtlesim_msgs/srv/SetPen";
}

template<>
struct has_fixed_size<turtlesim_msgs::srv::SetPen>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim_msgs::srv::SetPen_Request>::value &&
    has_fixed_size<turtlesim_msgs::srv::SetPen_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim_msgs::srv::SetPen>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim_msgs::srv::SetPen_Request>::value &&
    has_bounded_size<turtlesim_msgs::srv::SetPen_Response>::value
  >
{
};

template<>
struct is_service<turtlesim_msgs::srv::SetPen>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim_msgs::srv::SetPen_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim_msgs::srv::SetPen_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM_MSGS__SRV__DETAIL__SET_PEN__TRAITS_HPP_
