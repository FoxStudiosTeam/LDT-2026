// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pendulum_msgs:msg\RttestResults.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pendulum_msgs/msg/rttest_results.hpp"


#ifndef PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_HPP_
#define PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'command'
#include "pendulum_msgs/msg/detail/joint_command__struct.hpp"
// Member 'state'
#include "pendulum_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pendulum_msgs__msg__RttestResults __attribute__((deprecated))
#else
# define DEPRECATED__pendulum_msgs__msg__RttestResults __declspec(deprecated)
#endif

namespace pendulum_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RttestResults_
{
  using Type = RttestResults_<ContainerAllocator>;

  explicit RttestResults_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init),
    command(_init),
    state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cur_latency = 0ull;
      this->mean_latency = 0.0;
      this->min_latency = 0ull;
      this->max_latency = 0ull;
      this->minor_pagefaults = 0ull;
      this->major_pagefaults = 0ull;
    }
  }

  explicit RttestResults_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    command(_alloc, _init),
    state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cur_latency = 0ull;
      this->mean_latency = 0.0;
      this->min_latency = 0ull;
      this->max_latency = 0ull;
      this->minor_pagefaults = 0ull;
      this->major_pagefaults = 0ull;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _command_type =
    pendulum_msgs::msg::JointCommand_<ContainerAllocator>;
  _command_type command;
  using _state_type =
    pendulum_msgs::msg::JointState_<ContainerAllocator>;
  _state_type state;
  using _cur_latency_type =
    uint64_t;
  _cur_latency_type cur_latency;
  using _mean_latency_type =
    double;
  _mean_latency_type mean_latency;
  using _min_latency_type =
    uint64_t;
  _min_latency_type min_latency;
  using _max_latency_type =
    uint64_t;
  _max_latency_type max_latency;
  using _minor_pagefaults_type =
    uint64_t;
  _minor_pagefaults_type minor_pagefaults;
  using _major_pagefaults_type =
    uint64_t;
  _major_pagefaults_type major_pagefaults;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__command(
    const pendulum_msgs::msg::JointCommand_<ContainerAllocator> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__state(
    const pendulum_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__cur_latency(
    const uint64_t & _arg)
  {
    this->cur_latency = _arg;
    return *this;
  }
  Type & set__mean_latency(
    const double & _arg)
  {
    this->mean_latency = _arg;
    return *this;
  }
  Type & set__min_latency(
    const uint64_t & _arg)
  {
    this->min_latency = _arg;
    return *this;
  }
  Type & set__max_latency(
    const uint64_t & _arg)
  {
    this->max_latency = _arg;
    return *this;
  }
  Type & set__minor_pagefaults(
    const uint64_t & _arg)
  {
    this->minor_pagefaults = _arg;
    return *this;
  }
  Type & set__major_pagefaults(
    const uint64_t & _arg)
  {
    this->major_pagefaults = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pendulum_msgs::msg::RttestResults_<ContainerAllocator> *;
  using ConstRawPtr =
    const pendulum_msgs::msg::RttestResults_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pendulum_msgs::msg::RttestResults_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pendulum_msgs::msg::RttestResults_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pendulum_msgs__msg__RttestResults
    std::shared_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pendulum_msgs__msg__RttestResults
    std::shared_ptr<pendulum_msgs::msg::RttestResults_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RttestResults_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->command != other.command) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->cur_latency != other.cur_latency) {
      return false;
    }
    if (this->mean_latency != other.mean_latency) {
      return false;
    }
    if (this->min_latency != other.min_latency) {
      return false;
    }
    if (this->max_latency != other.max_latency) {
      return false;
    }
    if (this->minor_pagefaults != other.minor_pagefaults) {
      return false;
    }
    if (this->major_pagefaults != other.major_pagefaults) {
      return false;
    }
    return true;
  }
  bool operator!=(const RttestResults_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RttestResults_

// alias to use template instance with default allocator
using RttestResults =
  pendulum_msgs::msg::RttestResults_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pendulum_msgs

#endif  // PENDULUM_MSGS__MSG__DETAIL__RTTEST_RESULTS__STRUCT_HPP_
