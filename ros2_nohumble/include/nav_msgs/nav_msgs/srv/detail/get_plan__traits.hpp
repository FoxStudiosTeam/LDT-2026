// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nav_msgs:srv\GetPlan.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/srv/get_plan.hpp"


#ifndef NAV_MSGS__SRV__DETAIL__GET_PLAN__TRAITS_HPP_
#define NAV_MSGS__SRV__DETAIL__GET_PLAN__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "nav_msgs/srv/detail/get_plan__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPlan_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    to_flow_style_yaml(msg.start, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
    out << ", ";
  }

  // member: tolerance
  {
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPlan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start:\n";
    to_block_style_yaml(msg.start, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }

  // member: tolerance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPlan_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::GetPlan_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).start,
    std::forward<T>(msg).goal,
    std::forward<T>(msg).tolerance);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::GetPlan_Request>()
{
  return "nav_msgs::srv::GetPlan_Request";
}

template<>
constexpr const char * name<nav_msgs::srv::GetPlan_Request>()
{
  return "nav_msgs/srv/GetPlan_Request";
}

template<>
struct has_fixed_size<nav_msgs::srv::GetPlan_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<nav_msgs::srv::GetPlan_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<nav_msgs::srv::GetPlan_Request>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::GetPlan_Request>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "start",
    "goal",
    "tolerance",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'plan'
#include "nav_msgs/msg/detail/path__traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPlan_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: plan
  {
    out << "plan: ";
    to_flow_style_yaml(msg.plan, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPlan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: plan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plan:\n";
    to_block_style_yaml(msg.plan, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPlan_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::GetPlan_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).plan);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::GetPlan_Response>()
{
  return "nav_msgs::srv::GetPlan_Response";
}

template<>
constexpr const char * name<nav_msgs::srv::GetPlan_Response>()
{
  return "nav_msgs/srv/GetPlan_Response";
}

template<>
struct has_fixed_size<nav_msgs::srv::GetPlan_Response>
  : std::integral_constant<bool, has_fixed_size<nav_msgs::msg::Path>::value> {};

template<>
struct has_bounded_size<nav_msgs::srv::GetPlan_Response>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::msg::Path>::value> {};

template<>
struct is_message<nav_msgs::srv::GetPlan_Response>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::GetPlan_Response>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "plan",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace nav_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPlan_Event & msg,
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
  const GetPlan_Event & msg,
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

inline std::string to_yaml(const GetPlan_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, nav_msgs::srv::GetPlan_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace nav_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<nav_msgs::srv::GetPlan_Event>()
{
  return "nav_msgs::srv::GetPlan_Event";
}

template<>
constexpr const char * name<nav_msgs::srv::GetPlan_Event>()
{
  return "nav_msgs/srv/GetPlan_Event";
}

template<>
struct has_fixed_size<nav_msgs::srv::GetPlan_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nav_msgs::srv::GetPlan_Event>
  : std::integral_constant<bool, has_bounded_size<nav_msgs::srv::GetPlan_Request>::value && has_bounded_size<nav_msgs::srv::GetPlan_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<nav_msgs::srv::GetPlan_Event>
  : std::true_type {};

template<>
struct MessageTraits<nav_msgs::srv::GetPlan_Event>
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
constexpr const char * data_type<nav_msgs::srv::GetPlan>()
{
  return "nav_msgs::srv::GetPlan";
}

template<>
constexpr const char * name<nav_msgs::srv::GetPlan>()
{
  return "nav_msgs/srv/GetPlan";
}

template<>
struct has_fixed_size<nav_msgs::srv::GetPlan>
  : std::integral_constant<
    bool,
    has_fixed_size<nav_msgs::srv::GetPlan_Request>::value &&
    has_fixed_size<nav_msgs::srv::GetPlan_Response>::value
  >
{
};

template<>
struct has_bounded_size<nav_msgs::srv::GetPlan>
  : std::integral_constant<
    bool,
    has_bounded_size<nav_msgs::srv::GetPlan_Request>::value &&
    has_bounded_size<nav_msgs::srv::GetPlan_Response>::value
  >
{
};

template<>
struct is_service<nav_msgs::srv::GetPlan>
  : std::true_type
{
};

template<>
struct is_service_request<nav_msgs::srv::GetPlan_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nav_msgs::srv::GetPlan_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAV_MSGS__SRV__DETAIL__GET_PLAN__TRAITS_HPP_
