// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from visualization_msgs:srv\GetInteractiveMarkers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "visualization_msgs/srv/get_interactive_markers.hpp"


#ifndef VISUALIZATION_MSGS__SRV__DETAIL__GET_INTERACTIVE_MARKERS__TRAITS_HPP_
#define VISUALIZATION_MSGS__SRV__DETAIL__GET_INTERACTIVE_MARKERS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "visualization_msgs/srv/detail/get_interactive_markers__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace visualization_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetInteractiveMarkers_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetInteractiveMarkers_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetInteractiveMarkers_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::srv::GetInteractiveMarkers_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace srv

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::srv::GetInteractiveMarkers_Request>()
{
  return "visualization_msgs::srv::GetInteractiveMarkers_Request";
}

template<>
constexpr const char * name<visualization_msgs::srv::GetInteractiveMarkers_Request>()
{
  return "visualization_msgs/srv/GetInteractiveMarkers_Request";
}

template<>
struct has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<visualization_msgs::srv::GetInteractiveMarkers_Request>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::srv::GetInteractiveMarkers_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "structure_needs_at_least_one_member",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'markers'
#include "visualization_msgs/msg/detail/interactive_marker__traits.hpp"

namespace visualization_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetInteractiveMarkers_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sequence_number
  {
    out << "sequence_number: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_number, out);
    out << ", ";
  }

  // member: markers
  {
    if (msg.markers.size() == 0) {
      out << "markers: []";
    } else {
      out << "markers: [";
      size_t pending_items = msg.markers.size();
      for (auto item : msg.markers) {
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
  const GetInteractiveMarkers_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sequence_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence_number: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence_number, out);
    out << "\n";
  }

  // member: markers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.markers.size() == 0) {
      out << "markers: []\n";
    } else {
      out << "markers:\n";
      for (auto item : msg.markers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetInteractiveMarkers_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::srv::GetInteractiveMarkers_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).sequence_number,
    std::forward<T>(msg).markers);
}

}  // namespace srv

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::srv::GetInteractiveMarkers_Response>()
{
  return "visualization_msgs::srv::GetInteractiveMarkers_Response";
}

template<>
constexpr const char * name<visualization_msgs::srv::GetInteractiveMarkers_Response>()
{
  return "visualization_msgs/srv/GetInteractiveMarkers_Response";
}

template<>
struct has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<visualization_msgs::srv::GetInteractiveMarkers_Response>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::srv::GetInteractiveMarkers_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "sequence_number",
    "markers",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace visualization_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetInteractiveMarkers_Event & msg,
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
  const GetInteractiveMarkers_Event & msg,
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

inline std::string to_yaml(const GetInteractiveMarkers_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, visualization_msgs::srv::GetInteractiveMarkers_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace visualization_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<visualization_msgs::srv::GetInteractiveMarkers_Event>()
{
  return "visualization_msgs::srv::GetInteractiveMarkers_Event";
}

template<>
constexpr const char * name<visualization_msgs::srv::GetInteractiveMarkers_Event>()
{
  return "visualization_msgs/srv/GetInteractiveMarkers_Event";
}

template<>
struct has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Request>::value && has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Response>::value> {};

template<>
struct is_message<visualization_msgs::srv::GetInteractiveMarkers_Event>
  : std::true_type {};

template<>
struct MessageTraits<visualization_msgs::srv::GetInteractiveMarkers_Event>
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
constexpr const char * data_type<visualization_msgs::srv::GetInteractiveMarkers>()
{
  return "visualization_msgs::srv::GetInteractiveMarkers";
}

template<>
constexpr const char * name<visualization_msgs::srv::GetInteractiveMarkers>()
{
  return "visualization_msgs/srv/GetInteractiveMarkers";
}

template<>
struct has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers>
  : std::integral_constant<
    bool,
    has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers_Request>::value &&
    has_fixed_size<visualization_msgs::srv::GetInteractiveMarkers_Response>::value
  >
{
};

template<>
struct has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers>
  : std::integral_constant<
    bool,
    has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Request>::value &&
    has_bounded_size<visualization_msgs::srv::GetInteractiveMarkers_Response>::value
  >
{
};

template<>
struct is_service<visualization_msgs::srv::GetInteractiveMarkers>
  : std::true_type
{
};

template<>
struct is_service_request<visualization_msgs::srv::GetInteractiveMarkers_Request>
  : std::true_type
{
};

template<>
struct is_service_response<visualization_msgs::srv::GetInteractiveMarkers_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VISUALIZATION_MSGS__SRV__DETAIL__GET_INTERACTIVE_MARKERS__TRAITS_HPP_
