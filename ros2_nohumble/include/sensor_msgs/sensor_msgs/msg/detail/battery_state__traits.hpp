// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sensor_msgs:msg\BatteryState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sensor_msgs/msg/battery_state.hpp"


#ifndef SENSOR_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
#define SENSOR_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "sensor_msgs/msg/detail/battery_state__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: voltage
  {
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: charge
  {
    out << "charge: ";
    rosidl_generator_traits::value_to_yaml(msg.charge, out);
    out << ", ";
  }

  // member: capacity
  {
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << ", ";
  }

  // member: design_capacity
  {
    out << "design_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.design_capacity, out);
    out << ", ";
  }

  // member: percentage
  {
    out << "percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.percentage, out);
    out << ", ";
  }

  // member: power_supply_status
  {
    out << "power_supply_status: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_status, out);
    out << ", ";
  }

  // member: power_supply_health
  {
    out << "power_supply_health: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_health, out);
    out << ", ";
  }

  // member: power_supply_technology
  {
    out << "power_supply_technology: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_technology, out);
    out << ", ";
  }

  // member: present
  {
    out << "present: ";
    rosidl_generator_traits::value_to_yaml(msg.present, out);
    out << ", ";
  }

  // member: cell_voltage
  {
    if (msg.cell_voltage.size() == 0) {
      out << "cell_voltage: []";
    } else {
      out << "cell_voltage: [";
      size_t pending_items = msg.cell_voltage.size();
      for (auto item : msg.cell_voltage) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: cell_temperature
  {
    if (msg.cell_temperature.size() == 0) {
      out << "cell_temperature: []";
    } else {
      out << "cell_temperature: [";
      size_t pending_items = msg.cell_temperature.size();
      for (auto item : msg.cell_temperature) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: location
  {
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
    out << ", ";
  }

  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.voltage, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge: ";
    rosidl_generator_traits::value_to_yaml(msg.charge, out);
    out << "\n";
  }

  // member: capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity, out);
    out << "\n";
  }

  // member: design_capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "design_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.design_capacity, out);
    out << "\n";
  }

  // member: percentage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.percentage, out);
    out << "\n";
  }

  // member: power_supply_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_supply_status: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_status, out);
    out << "\n";
  }

  // member: power_supply_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_supply_health: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_health, out);
    out << "\n";
  }

  // member: power_supply_technology
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_supply_technology: ";
    rosidl_generator_traits::value_to_yaml(msg.power_supply_technology, out);
    out << "\n";
  }

  // member: present
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "present: ";
    rosidl_generator_traits::value_to_yaml(msg.present, out);
    out << "\n";
  }

  // member: cell_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cell_voltage.size() == 0) {
      out << "cell_voltage: []\n";
    } else {
      out << "cell_voltage:\n";
      for (auto item : msg.cell_voltage) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: cell_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cell_temperature.size() == 0) {
      out << "cell_temperature: []\n";
    } else {
      out << "cell_temperature:\n";
      for (auto item : msg.cell_temperature) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: location
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
    out << "\n";
  }

  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, sensor_msgs::msg::BatteryState>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).header,
    std::forward<T>(msg).voltage,
    std::forward<T>(msg).temperature,
    std::forward<T>(msg).current,
    std::forward<T>(msg).charge,
    std::forward<T>(msg).capacity,
    std::forward<T>(msg).design_capacity,
    std::forward<T>(msg).percentage,
    std::forward<T>(msg).power_supply_status,
    std::forward<T>(msg).power_supply_health,
    std::forward<T>(msg).power_supply_technology,
    std::forward<T>(msg).present,
    std::forward<T>(msg).cell_voltage,
    std::forward<T>(msg).cell_temperature,
    std::forward<T>(msg).location,
    std::forward<T>(msg).serial_number);
}

}  // namespace msg

}  // namespace sensor_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<sensor_msgs::msg::BatteryState>()
{
  return "sensor_msgs::msg::BatteryState";
}

template<>
constexpr const char * name<sensor_msgs::msg::BatteryState>()
{
  return "sensor_msgs/msg/BatteryState";
}

template<>
struct has_fixed_size<sensor_msgs::msg::BatteryState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sensor_msgs::msg::BatteryState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sensor_msgs::msg::BatteryState>
  : std::true_type {};

template<>
struct MessageTraits<sensor_msgs::msg::BatteryState>
{
  static constexpr std::size_t member_count = 16;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "header",
    "voltage",
    "temperature",
    "current",
    "charge",
    "capacity",
    "design_capacity",
    "percentage",
    "power_supply_status",
    "power_supply_health",
    "power_supply_technology",
    "present",
    "cell_voltage",
    "cell_temperature",
    "location",
    "serial_number",
  };
};

}  // namespace rosidl_generator_traits

#endif  // SENSOR_MSGS__MSG__DETAIL__BATTERY_STATE__TRAITS_HPP_
