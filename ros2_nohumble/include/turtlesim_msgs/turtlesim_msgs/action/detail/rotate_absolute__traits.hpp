// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim_msgs:action\RotateAbsolute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/action/rotate_absolute.hpp"


#ifndef TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__TRAITS_HPP_
#define TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "turtlesim_msgs/action/detail/rotate_absolute__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_Goal>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).theta);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_Goal>()
{
  return "turtlesim_msgs::action::RotateAbsolute_Goal";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_Goal>()
{
  return "turtlesim_msgs/action/RotateAbsolute_Goal";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_Goal>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_Goal>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "theta",
  };
};

}  // namespace rosidl_generator_traits

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: delta
  {
    out << "delta: ";
    rosidl_generator_traits::value_to_yaml(msg.delta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: delta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delta: ";
    rosidl_generator_traits::value_to_yaml(msg.delta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_Result>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).delta);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_Result>()
{
  return "turtlesim_msgs::action::RotateAbsolute_Result";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_Result>()
{
  return "turtlesim_msgs/action/RotateAbsolute_Result";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_Result>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_Result>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "delta",
  };
};

}  // namespace rosidl_generator_traits

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: remaining
  {
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_Feedback>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).remaining);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_Feedback>()
{
  return "turtlesim_msgs::action::RotateAbsolute_Feedback";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_Feedback>()
{
  return "turtlesim_msgs/action/RotateAbsolute_Feedback";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_Feedback>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_Feedback>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "remaining",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "turtlesim_msgs/action/detail/rotate_absolute__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).goal_id,
    std::forward<T>(msg).goal);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>()
{
  return "turtlesim_msgs::action::RotateAbsolute_SendGoal_Request";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>()
{
  return "turtlesim_msgs/action/RotateAbsolute_SendGoal_Request";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "goal_id",
    "goal",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).accepted,
    std::forward<T>(msg).stamp);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>()
{
  return "turtlesim_msgs::action::RotateAbsolute_SendGoal_Response";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>()
{
  return "turtlesim_msgs/action/RotateAbsolute_SendGoal_Response";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "accepted",
    "stamp",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_SendGoal_Event & msg,
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
  const RotateAbsolute_SendGoal_Event & msg,
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

inline std::string to_yaml(const RotateAbsolute_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>()
{
  return "turtlesim_msgs::action::RotateAbsolute_SendGoal_Event";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>()
{
  return "turtlesim_msgs/action/RotateAbsolute_SendGoal_Event";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>::value && has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>
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
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_SendGoal>()
{
  return "turtlesim_msgs::action::RotateAbsolute_SendGoal";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_SendGoal>()
{
  return "turtlesim_msgs/action/RotateAbsolute_SendGoal";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>::value &&
    has_fixed_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>::value &&
    has_bounded_size<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<turtlesim_msgs::action::RotateAbsolute_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_GetResult_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).goal_id);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>()
{
  return "turtlesim_msgs::action::RotateAbsolute_GetResult_Request";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>()
{
  return "turtlesim_msgs/action/RotateAbsolute_GetResult_Request";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "goal_id",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_GetResult_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).status,
    std::forward<T>(msg).result);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>()
{
  return "turtlesim_msgs::action::RotateAbsolute_GetResult_Response";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>()
{
  return "turtlesim_msgs/action/RotateAbsolute_GetResult_Response";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Result>::value> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Result>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "status",
    "result",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_GetResult_Event & msg,
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
  const RotateAbsolute_GetResult_Event & msg,
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

inline std::string to_yaml(const RotateAbsolute_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_GetResult_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>()
{
  return "turtlesim_msgs::action::RotateAbsolute_GetResult_Event";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>()
{
  return "turtlesim_msgs/action/RotateAbsolute_GetResult_Event";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>::value && has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_GetResult_Event>
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
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_GetResult>()
{
  return "turtlesim_msgs::action::RotateAbsolute_GetResult";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_GetResult>()
{
  return "turtlesim_msgs/action/RotateAbsolute_GetResult";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>::value &&
    has_fixed_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>::value &&
    has_bounded_size<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>::value
  >
{
};

template<>
struct is_service<turtlesim_msgs::action::RotateAbsolute_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim_msgs::action::RotateAbsolute_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim_msgs::action::RotateAbsolute_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "turtlesim_msgs/action/detail/rotate_absolute__traits.hpp"

namespace turtlesim_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateAbsolute_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateAbsolute_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateAbsolute_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).goal_id,
    std::forward<T>(msg).feedback);
}

}  // namespace action

}  // namespace turtlesim_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>()
{
  return "turtlesim_msgs::action::RotateAbsolute_FeedbackMessage";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>()
{
  return "turtlesim_msgs/action/RotateAbsolute_FeedbackMessage";
}

template<>
struct has_fixed_size<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<turtlesim_msgs::action::RotateAbsolute_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<turtlesim_msgs::action::RotateAbsolute_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>
  : std::true_type {};

template<>
struct MessageTraits<turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "goal_id",
    "feedback",
  };
};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<turtlesim_msgs::action::RotateAbsolute>()
{
  return "turtlesim_msgs::action::RotateAbsolute";
}

template<>
constexpr const char * name<turtlesim_msgs::action::RotateAbsolute>()
{
  return "turtlesim_msgs/action/RotateAbsolute";
}

template<>
struct is_action<turtlesim_msgs::action::RotateAbsolute>
  : std::true_type
{
};

template<>
struct is_action_goal<turtlesim_msgs::action::RotateAbsolute_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<turtlesim_msgs::action::RotateAbsolute_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<turtlesim_msgs::action::RotateAbsolute_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__TRAITS_HPP_
