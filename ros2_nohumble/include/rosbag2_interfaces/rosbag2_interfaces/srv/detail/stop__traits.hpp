// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_interfaces:srv\Stop.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/stop.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__STOP__TRAITS_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__STOP__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosbag2_interfaces/srv/detail/stop__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosbag2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Stop_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Stop_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Stop_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::srv::Stop_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace srv

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::srv::Stop_Request>()
{
  return "rosbag2_interfaces::srv::Stop_Request";
}

template<>
constexpr const char * name<rosbag2_interfaces::srv::Stop_Request>()
{
  return "rosbag2_interfaces/srv/Stop_Request";
}

template<>
struct has_fixed_size<rosbag2_interfaces::srv::Stop_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rosbag2_interfaces::srv::Stop_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rosbag2_interfaces::srv::Stop_Request>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::srv::Stop_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "structure_needs_at_least_one_member",
  };
};

}  // namespace rosidl_generator_traits

namespace rosbag2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Stop_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: return_code
  {
    out << "return_code: ";
    rosidl_generator_traits::value_to_yaml(msg.return_code, out);
    out << ", ";
  }

  // member: error_string
  {
    out << "error_string: ";
    rosidl_generator_traits::value_to_yaml(msg.error_string, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Stop_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: return_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "return_code: ";
    rosidl_generator_traits::value_to_yaml(msg.return_code, out);
    out << "\n";
  }

  // member: error_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_string: ";
    rosidl_generator_traits::value_to_yaml(msg.error_string, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Stop_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::srv::Stop_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).return_code,
    std::forward<T>(msg).error_string);
}

}  // namespace srv

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::srv::Stop_Response>()
{
  return "rosbag2_interfaces::srv::Stop_Response";
}

template<>
constexpr const char * name<rosbag2_interfaces::srv::Stop_Response>()
{
  return "rosbag2_interfaces/srv/Stop_Response";
}

template<>
struct has_fixed_size<rosbag2_interfaces::srv::Stop_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_interfaces::srv::Stop_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_interfaces::srv::Stop_Response>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::srv::Stop_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "return_code",
    "error_string",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace rosbag2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Stop_Event & msg,
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
  const Stop_Event & msg,
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

inline std::string to_yaml(const Stop_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosbag2_interfaces::srv::Stop_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace rosbag2_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosbag2_interfaces::srv::Stop_Event>()
{
  return "rosbag2_interfaces::srv::Stop_Event";
}

template<>
constexpr const char * name<rosbag2_interfaces::srv::Stop_Event>()
{
  return "rosbag2_interfaces/srv/Stop_Event";
}

template<>
struct has_fixed_size<rosbag2_interfaces::srv::Stop_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_interfaces::srv::Stop_Event>
  : std::integral_constant<bool, has_bounded_size<rosbag2_interfaces::srv::Stop_Request>::value && has_bounded_size<rosbag2_interfaces::srv::Stop_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<rosbag2_interfaces::srv::Stop_Event>
  : std::true_type {};

template<>
struct MessageTraits<rosbag2_interfaces::srv::Stop_Event>
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
constexpr const char * data_type<rosbag2_interfaces::srv::Stop>()
{
  return "rosbag2_interfaces::srv::Stop";
}

template<>
constexpr const char * name<rosbag2_interfaces::srv::Stop>()
{
  return "rosbag2_interfaces/srv/Stop";
}

template<>
struct has_fixed_size<rosbag2_interfaces::srv::Stop>
  : std::integral_constant<
    bool,
    has_fixed_size<rosbag2_interfaces::srv::Stop_Request>::value &&
    has_fixed_size<rosbag2_interfaces::srv::Stop_Response>::value
  >
{
};

template<>
struct has_bounded_size<rosbag2_interfaces::srv::Stop>
  : std::integral_constant<
    bool,
    has_bounded_size<rosbag2_interfaces::srv::Stop_Request>::value &&
    has_bounded_size<rosbag2_interfaces::srv::Stop_Response>::value
  >
{
};

template<>
struct is_service<rosbag2_interfaces::srv::Stop>
  : std::true_type
{
};

template<>
struct is_service_request<rosbag2_interfaces::srv::Stop_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rosbag2_interfaces::srv::Stop_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__STOP__TRAITS_HPP_
