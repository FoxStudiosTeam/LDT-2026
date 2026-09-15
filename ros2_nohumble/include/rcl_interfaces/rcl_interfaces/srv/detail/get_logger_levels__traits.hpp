// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rcl_interfaces:srv\GetLoggerLevels.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rcl_interfaces/srv/get_logger_levels.hpp"


#ifndef RCL_INTERFACES__SRV__DETAIL__GET_LOGGER_LEVELS__TRAITS_HPP_
#define RCL_INTERFACES__SRV__DETAIL__GET_LOGGER_LEVELS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rcl_interfaces/srv/detail/get_logger_levels__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rcl_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetLoggerLevels_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: names
  {
    if (msg.names.size() == 0) {
      out << "names: []";
    } else {
      out << "names: [";
      size_t pending_items = msg.names.size();
      for (auto item : msg.names) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const GetLoggerLevels_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.names.size() == 0) {
      out << "names: []\n";
    } else {
      out << "names:\n";
      for (auto item : msg.names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetLoggerLevels_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::srv::GetLoggerLevels_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).names);
}

}  // namespace srv

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::srv::GetLoggerLevels_Request>()
{
  return "rcl_interfaces::srv::GetLoggerLevels_Request";
}

template<>
constexpr const char * name<rcl_interfaces::srv::GetLoggerLevels_Request>()
{
  return "rcl_interfaces/srv/GetLoggerLevels_Request";
}

template<>
struct has_fixed_size<rcl_interfaces::srv::GetLoggerLevels_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rcl_interfaces::srv::GetLoggerLevels_Request>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::srv::GetLoggerLevels_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "names",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'levels'
#include "rcl_interfaces/msg/detail/logger_level__traits.hpp"

namespace rcl_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetLoggerLevels_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: levels
  {
    if (msg.levels.size() == 0) {
      out << "levels: []";
    } else {
      out << "levels: [";
      size_t pending_items = msg.levels.size();
      for (auto item : msg.levels) {
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
  const GetLoggerLevels_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: levels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.levels.size() == 0) {
      out << "levels: []\n";
    } else {
      out << "levels:\n";
      for (auto item : msg.levels) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetLoggerLevels_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::srv::GetLoggerLevels_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).levels);
}

}  // namespace srv

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::srv::GetLoggerLevels_Response>()
{
  return "rcl_interfaces::srv::GetLoggerLevels_Response";
}

template<>
constexpr const char * name<rcl_interfaces::srv::GetLoggerLevels_Response>()
{
  return "rcl_interfaces/srv/GetLoggerLevels_Response";
}

template<>
struct has_fixed_size<rcl_interfaces::srv::GetLoggerLevels_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rcl_interfaces::srv::GetLoggerLevels_Response>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::srv::GetLoggerLevels_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "levels",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace rcl_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetLoggerLevels_Event & msg,
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
  const GetLoggerLevels_Event & msg,
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

inline std::string to_yaml(const GetLoggerLevels_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rcl_interfaces::srv::GetLoggerLevels_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace rcl_interfaces

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rcl_interfaces::srv::GetLoggerLevels_Event>()
{
  return "rcl_interfaces::srv::GetLoggerLevels_Event";
}

template<>
constexpr const char * name<rcl_interfaces::srv::GetLoggerLevels_Event>()
{
  return "rcl_interfaces/srv/GetLoggerLevels_Event";
}

template<>
struct has_fixed_size<rcl_interfaces::srv::GetLoggerLevels_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Event>
  : std::integral_constant<bool, has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Request>::value && has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<rcl_interfaces::srv::GetLoggerLevels_Event>
  : std::true_type {};

template<>
struct MessageTraits<rcl_interfaces::srv::GetLoggerLevels_Event>
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
constexpr const char * data_type<rcl_interfaces::srv::GetLoggerLevels>()
{
  return "rcl_interfaces::srv::GetLoggerLevels";
}

template<>
constexpr const char * name<rcl_interfaces::srv::GetLoggerLevels>()
{
  return "rcl_interfaces/srv/GetLoggerLevels";
}

template<>
struct has_fixed_size<rcl_interfaces::srv::GetLoggerLevels>
  : std::integral_constant<
    bool,
    has_fixed_size<rcl_interfaces::srv::GetLoggerLevels_Request>::value &&
    has_fixed_size<rcl_interfaces::srv::GetLoggerLevels_Response>::value
  >
{
};

template<>
struct has_bounded_size<rcl_interfaces::srv::GetLoggerLevels>
  : std::integral_constant<
    bool,
    has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Request>::value &&
    has_bounded_size<rcl_interfaces::srv::GetLoggerLevels_Response>::value
  >
{
};

template<>
struct is_service<rcl_interfaces::srv::GetLoggerLevels>
  : std::true_type
{
};

template<>
struct is_service_request<rcl_interfaces::srv::GetLoggerLevels_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rcl_interfaces::srv::GetLoggerLevels_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__SRV__DETAIL__GET_LOGGER_LEVELS__TRAITS_HPP_
