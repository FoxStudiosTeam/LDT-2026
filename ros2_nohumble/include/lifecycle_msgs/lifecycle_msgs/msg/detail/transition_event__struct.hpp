// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lifecycle_msgs:msg\TransitionEvent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "lifecycle_msgs/msg/transition_event.hpp"


#ifndef LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_EVENT__STRUCT_HPP_
#define LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_EVENT__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'transition'
#include "lifecycle_msgs/msg/detail/transition__struct.hpp"
// Member 'start_state'
// Member 'goal_state'
#include "lifecycle_msgs/msg/detail/state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lifecycle_msgs__msg__TransitionEvent __attribute__((deprecated))
#else
# define DEPRECATED__lifecycle_msgs__msg__TransitionEvent __declspec(deprecated)
#endif

namespace lifecycle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TransitionEvent_
{
  using Type = TransitionEvent_<ContainerAllocator>;

  explicit TransitionEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init),
    transition(_init),
    start_state(_init),
    goal_state(_init)
  {
    (void)_init;
  }

  explicit TransitionEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    transition(_alloc, _init),
    start_state(_alloc, _init),
    goal_state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _transition_type =
    lifecycle_msgs::msg::Transition_<ContainerAllocator>;
  _transition_type transition;
  using _start_state_type =
    lifecycle_msgs::msg::State_<ContainerAllocator>;
  _start_state_type start_state;
  using _goal_state_type =
    lifecycle_msgs::msg::State_<ContainerAllocator>;
  _goal_state_type goal_state;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__transition(
    const lifecycle_msgs::msg::Transition_<ContainerAllocator> & _arg)
  {
    this->transition = _arg;
    return *this;
  }
  Type & set__start_state(
    const lifecycle_msgs::msg::State_<ContainerAllocator> & _arg)
  {
    this->start_state = _arg;
    return *this;
  }
  Type & set__goal_state(
    const lifecycle_msgs::msg::State_<ContainerAllocator> & _arg)
  {
    this->goal_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lifecycle_msgs__msg__TransitionEvent
    std::shared_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lifecycle_msgs__msg__TransitionEvent
    std::shared_ptr<lifecycle_msgs::msg::TransitionEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TransitionEvent_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->transition != other.transition) {
      return false;
    }
    if (this->start_state != other.start_state) {
      return false;
    }
    if (this->goal_state != other.goal_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const TransitionEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TransitionEvent_

// alias to use template instance with default allocator
using TransitionEvent =
  lifecycle_msgs::msg::TransitionEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lifecycle_msgs

#endif  // LIFECYCLE_MSGS__MSG__DETAIL__TRANSITION_EVENT__STRUCT_HPP_
