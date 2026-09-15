// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\Node.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/node.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__NODE__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__NODE__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'parameters'
#include "rcl_interfaces/msg/detail/parameter_descriptor__struct.hpp"
// Member 'parameter_values'
#include "rcl_interfaces/msg/detail/parameter_value__struct.hpp"
// Member 'publishers'
// Member 'subscriptions'
#include "rosgraph_msgs/msg/detail/topic__struct.hpp"
// Member 'service_clients'
// Member 'service_servers'
#include "rosgraph_msgs/msg/detail/service__struct.hpp"
// Member 'action_clients'
// Member 'action_servers'
#include "rosgraph_msgs/msg/detail/action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__Node __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__Node __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Node_
{
  using Type = Node_<ContainerAllocator>;

  explicit Node_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit Node_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _parameters_type =
    std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>>;
  _parameters_type parameters;
  using _parameter_values_type =
    std::vector<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>>;
  _parameter_values_type parameter_values;
  using _publishers_type =
    std::vector<rosgraph_msgs::msg::Topic_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Topic_<ContainerAllocator>>>;
  _publishers_type publishers;
  using _subscriptions_type =
    std::vector<rosgraph_msgs::msg::Topic_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Topic_<ContainerAllocator>>>;
  _subscriptions_type subscriptions;
  using _service_clients_type =
    std::vector<rosgraph_msgs::msg::Service_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Service_<ContainerAllocator>>>;
  _service_clients_type service_clients;
  using _service_servers_type =
    std::vector<rosgraph_msgs::msg::Service_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Service_<ContainerAllocator>>>;
  _service_servers_type service_servers;
  using _action_clients_type =
    std::vector<rosgraph_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Action_<ContainerAllocator>>>;
  _action_clients_type action_clients;
  using _action_servers_type =
    std::vector<rosgraph_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Action_<ContainerAllocator>>>;
  _action_servers_type action_servers;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__parameters(
    const std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>> & _arg)
  {
    this->parameters = _arg;
    return *this;
  }
  Type & set__parameter_values(
    const std::vector<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>> & _arg)
  {
    this->parameter_values = _arg;
    return *this;
  }
  Type & set__publishers(
    const std::vector<rosgraph_msgs::msg::Topic_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Topic_<ContainerAllocator>>> & _arg)
  {
    this->publishers = _arg;
    return *this;
  }
  Type & set__subscriptions(
    const std::vector<rosgraph_msgs::msg::Topic_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Topic_<ContainerAllocator>>> & _arg)
  {
    this->subscriptions = _arg;
    return *this;
  }
  Type & set__service_clients(
    const std::vector<rosgraph_msgs::msg::Service_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Service_<ContainerAllocator>>> & _arg)
  {
    this->service_clients = _arg;
    return *this;
  }
  Type & set__service_servers(
    const std::vector<rosgraph_msgs::msg::Service_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Service_<ContainerAllocator>>> & _arg)
  {
    this->service_servers = _arg;
    return *this;
  }
  Type & set__action_clients(
    const std::vector<rosgraph_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Action_<ContainerAllocator>>> & _arg)
  {
    this->action_clients = _arg;
    return *this;
  }
  Type & set__action_servers(
    const std::vector<rosgraph_msgs::msg::Action_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rosgraph_msgs::msg::Action_<ContainerAllocator>>> & _arg)
  {
    this->action_servers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::Node_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::Node_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Node_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Node_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__Node
    std::shared_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__Node
    std::shared_ptr<rosgraph_msgs::msg::Node_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Node_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->parameters != other.parameters) {
      return false;
    }
    if (this->parameter_values != other.parameter_values) {
      return false;
    }
    if (this->publishers != other.publishers) {
      return false;
    }
    if (this->subscriptions != other.subscriptions) {
      return false;
    }
    if (this->service_clients != other.service_clients) {
      return false;
    }
    if (this->service_servers != other.service_servers) {
      return false;
    }
    if (this->action_clients != other.action_clients) {
      return false;
    }
    if (this->action_servers != other.action_servers) {
      return false;
    }
    return true;
  }
  bool operator!=(const Node_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Node_

// alias to use template instance with default allocator
using Node =
  rosgraph_msgs::msg::Node_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__NODE__STRUCT_HPP_
