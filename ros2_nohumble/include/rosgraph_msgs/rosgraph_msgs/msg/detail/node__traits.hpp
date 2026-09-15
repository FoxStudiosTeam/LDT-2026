// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/node.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "rosgraph_msgs/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'parameters'
#include "rcl_interfaces/msg/detail/parameter_descriptor__traits.hpp"
// Member 'parameter_values'
#include "rcl_interfaces/msg/detail/parameter_value__traits.hpp"
// Member 'publishers'
// Member 'subscriptions'
#include "rosgraph_msgs/msg/detail/topic__traits.hpp"
// Member 'service_clients'
// Member 'service_servers'
#include "rosgraph_msgs/msg/detail/service__traits.hpp"
// Member 'action_clients'
// Member 'action_servers'
#include "rosgraph_msgs/msg/detail/action__traits.hpp"

namespace rosgraph_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Node & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: parameters
  {
    if (msg.parameters.size() == 0) {
      out << "parameters: []";
    } else {
      out << "parameters: [";
      size_t pending_items = msg.parameters.size();
      for (auto item : msg.parameters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: parameter_values
  {
    if (msg.parameter_values.size() == 0) {
      out << "parameter_values: []";
    } else {
      out << "parameter_values: [";
      size_t pending_items = msg.parameter_values.size();
      for (auto item : msg.parameter_values) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: publishers
  {
    if (msg.publishers.size() == 0) {
      out << "publishers: []";
    } else {
      out << "publishers: [";
      size_t pending_items = msg.publishers.size();
      for (auto item : msg.publishers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: subscriptions
  {
    if (msg.subscriptions.size() == 0) {
      out << "subscriptions: []";
    } else {
      out << "subscriptions: [";
      size_t pending_items = msg.subscriptions.size();
      for (auto item : msg.subscriptions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: service_clients
  {
    if (msg.service_clients.size() == 0) {
      out << "service_clients: []";
    } else {
      out << "service_clients: [";
      size_t pending_items = msg.service_clients.size();
      for (auto item : msg.service_clients) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: service_servers
  {
    if (msg.service_servers.size() == 0) {
      out << "service_servers: []";
    } else {
      out << "service_servers: [";
      size_t pending_items = msg.service_servers.size();
      for (auto item : msg.service_servers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: action_clients
  {
    if (msg.action_clients.size() == 0) {
      out << "action_clients: []";
    } else {
      out << "action_clients: [";
      size_t pending_items = msg.action_clients.size();
      for (auto item : msg.action_clients) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: action_servers
  {
    if (msg.action_servers.size() == 0) {
      out << "action_servers: []";
    } else {
      out << "action_servers: [";
      size_t pending_items = msg.action_servers.size();
      for (auto item : msg.action_servers) {
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
  const Node & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: parameters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.parameters.size() == 0) {
      out << "parameters: []\n";
    } else {
      out << "parameters:\n";
      for (auto item : msg.parameters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: parameter_values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.parameter_values.size() == 0) {
      out << "parameter_values: []\n";
    } else {
      out << "parameter_values:\n";
      for (auto item : msg.parameter_values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: publishers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.publishers.size() == 0) {
      out << "publishers: []\n";
    } else {
      out << "publishers:\n";
      for (auto item : msg.publishers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: subscriptions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.subscriptions.size() == 0) {
      out << "subscriptions: []\n";
    } else {
      out << "subscriptions:\n";
      for (auto item : msg.subscriptions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: service_clients
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.service_clients.size() == 0) {
      out << "service_clients: []\n";
    } else {
      out << "service_clients:\n";
      for (auto item : msg.service_clients) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: service_servers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.service_servers.size() == 0) {
      out << "service_servers: []\n";
    } else {
      out << "service_servers:\n";
      for (auto item : msg.service_servers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: action_clients
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action_clients.size() == 0) {
      out << "action_clients: []\n";
    } else {
      out << "action_clients:\n";
      for (auto item : msg.action_clients) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: action_servers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action_servers.size() == 0) {
      out << "action_servers: []\n";
    } else {
      out << "action_servers:\n";
      for (auto item : msg.action_servers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Node & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, rosgraph_msgs::msg::Node>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).name,
    std::forward<T>(msg).parameters,
    std::forward<T>(msg).parameter_values,
    std::forward<T>(msg).publishers,
    std::forward<T>(msg).subscriptions,
    std::forward<T>(msg).service_clients,
    std::forward<T>(msg).service_servers,
    std::forward<T>(msg).action_clients,
    std::forward<T>(msg).action_servers);
}

}  // namespace msg

}  // namespace rosgraph_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<rosgraph_msgs::msg::Node>()
{
  return "rosgraph_msgs::msg::Node";
}

template<>
constexpr const char * name<rosgraph_msgs::msg::Node>()
{
  return "rosgraph_msgs/msg/Node";
}

template<>
struct has_fixed_size<rosgraph_msgs::msg::Node>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosgraph_msgs::msg::Node>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosgraph_msgs::msg::Node>
  : std::true_type {};

template<>
struct MessageTraits<rosgraph_msgs::msg::Node>
{
  static constexpr std::size_t member_count = 9;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "name",
    "parameters",
    "parameter_values",
    "publishers",
    "subscriptions",
    "service_clients",
    "service_servers",
    "action_clients",
    "action_servers",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__NODE__TRAITS_HPP_
