// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_msgs:srv\GetMapROI.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/srv/get_map_roi.hpp"


#ifndef MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__TRAITS_HPP_
#define MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "map_msgs/srv/detail/get_map_roi__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMapROI_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: l_x
  {
    out << "l_x: ";
    rosidl_generator_traits::value_to_yaml(msg.l_x, out);
    out << ", ";
  }

  // member: l_y
  {
    out << "l_y: ";
    rosidl_generator_traits::value_to_yaml(msg.l_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetMapROI_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: l_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_x: ";
    rosidl_generator_traits::value_to_yaml(msg.l_x, out);
    out << "\n";
  }

  // member: l_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_y: ";
    rosidl_generator_traits::value_to_yaml(msg.l_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMapROI_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, map_msgs::srv::GetMapROI_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).x,
    std::forward<T>(msg).y,
    std::forward<T>(msg).l_x,
    std::forward<T>(msg).l_y);
}

}  // namespace srv

}  // namespace map_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<map_msgs::srv::GetMapROI_Request>()
{
  return "map_msgs::srv::GetMapROI_Request";
}

template<>
constexpr const char * name<map_msgs::srv::GetMapROI_Request>()
{
  return "map_msgs/srv/GetMapROI_Request";
}

template<>
struct has_fixed_size<map_msgs::srv::GetMapROI_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<map_msgs::srv::GetMapROI_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<map_msgs::srv::GetMapROI_Request>
  : std::true_type {};

template<>
struct MessageTraits<map_msgs::srv::GetMapROI_Request>
{
  static constexpr std::size_t member_count = 4;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "x",
    "y",
    "l_x",
    "l_y",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'sub_map'
#include "nav_msgs/msg/detail/occupancy_grid__traits.hpp"

namespace map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMapROI_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sub_map
  {
    out << "sub_map: ";
    to_flow_style_yaml(msg.sub_map, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetMapROI_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sub_map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sub_map:\n";
    to_block_style_yaml(msg.sub_map, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMapROI_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, map_msgs::srv::GetMapROI_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).sub_map);
}

}  // namespace srv

}  // namespace map_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<map_msgs::srv::GetMapROI_Response>()
{
  return "map_msgs::srv::GetMapROI_Response";
}

template<>
constexpr const char * name<map_msgs::srv::GetMapROI_Response>()
{
  return "map_msgs/srv/GetMapROI_Response";
}

template<>
struct has_fixed_size<map_msgs::srv::GetMapROI_Response>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct has_bounded_size<map_msgs::srv::GetMapROI_Response>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::OccupancyGrid>::value> {};

template<>
struct is_message<map_msgs::srv::GetMapROI_Response>
  : std::true_type {};

template<>
struct MessageTraits<map_msgs::srv::GetMapROI_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "sub_map",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMapROI_Event & msg,
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
  const GetMapROI_Event & msg,
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

inline std::string to_yaml(const GetMapROI_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, map_msgs::srv::GetMapROI_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace map_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<map_msgs::srv::GetMapROI_Event>()
{
  return "map_msgs::srv::GetMapROI_Event";
}

template<>
constexpr const char * name<map_msgs::srv::GetMapROI_Event>()
{
  return "map_msgs/srv/GetMapROI_Event";
}

template<>
struct has_fixed_size<map_msgs::srv::GetMapROI_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_msgs::srv::GetMapROI_Event>
  : std::integral_constant<bool, has_bounded_size<map_msgs::srv::GetMapROI_Request>::value && has_bounded_size<map_msgs::srv::GetMapROI_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<map_msgs::srv::GetMapROI_Event>
  : std::true_type {};

template<>
struct MessageTraits<map_msgs::srv::GetMapROI_Event>
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
constexpr const char * data_type<map_msgs::srv::GetMapROI>()
{
  return "map_msgs::srv::GetMapROI";
}

template<>
constexpr const char * name<map_msgs::srv::GetMapROI>()
{
  return "map_msgs/srv/GetMapROI";
}

template<>
struct has_fixed_size<map_msgs::srv::GetMapROI>
  : std::integral_constant<
    bool,
    has_fixed_size<map_msgs::srv::GetMapROI_Request>::value &&
    has_fixed_size<map_msgs::srv::GetMapROI_Response>::value
  >
{
};

template<>
struct has_bounded_size<map_msgs::srv::GetMapROI>
  : std::integral_constant<
    bool,
    has_bounded_size<map_msgs::srv::GetMapROI_Request>::value &&
    has_bounded_size<map_msgs::srv::GetMapROI_Response>::value
  >
{
};

template<>
struct is_service<map_msgs::srv::GetMapROI>
  : std::true_type
{
};

template<>
struct is_service_request<map_msgs::srv::GetMapROI_Request>
  : std::true_type
{
};

template<>
struct is_service_response<map_msgs::srv::GetMapROI_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MAP_MSGS__SRV__DETAIL__GET_MAP_ROI__TRAITS_HPP_
