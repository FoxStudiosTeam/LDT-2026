// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\Action.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/action.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__ACTION__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__ACTION__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'send_goal'
// Member 'get_result'
// Member 'cancel_goal'
#include "rosgraph_msgs/msg/detail/service__struct.hpp"
// Member 'feedback'
// Member 'status'
#include "rosgraph_msgs/msg/detail/topic__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__Action __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__Action __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Action_
{
  using Type = Action_<ContainerAllocator>;

  explicit Action_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : send_goal(_init),
    get_result(_init),
    cancel_goal(_init),
    feedback(_init),
    status(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit Action_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    send_goal(_alloc, _init),
    get_result(_alloc, _init),
    cancel_goal(_alloc, _init),
    feedback(_alloc, _init),
    status(_alloc, _init)
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
  using _send_goal_type =
    rosgraph_msgs::msg::Service_<ContainerAllocator>;
  _send_goal_type send_goal;
  using _get_result_type =
    rosgraph_msgs::msg::Service_<ContainerAllocator>;
  _get_result_type get_result;
  using _cancel_goal_type =
    rosgraph_msgs::msg::Service_<ContainerAllocator>;
  _cancel_goal_type cancel_goal;
  using _feedback_type =
    rosgraph_msgs::msg::Topic_<ContainerAllocator>;
  _feedback_type feedback;
  using _status_type =
    rosgraph_msgs::msg::Topic_<ContainerAllocator>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__send_goal(
    const rosgraph_msgs::msg::Service_<ContainerAllocator> & _arg)
  {
    this->send_goal = _arg;
    return *this;
  }
  Type & set__get_result(
    const rosgraph_msgs::msg::Service_<ContainerAllocator> & _arg)
  {
    this->get_result = _arg;
    return *this;
  }
  Type & set__cancel_goal(
    const rosgraph_msgs::msg::Service_<ContainerAllocator> & _arg)
  {
    this->cancel_goal = _arg;
    return *this;
  }
  Type & set__feedback(
    const rosgraph_msgs::msg::Topic_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }
  Type & set__status(
    const rosgraph_msgs::msg::Topic_<ContainerAllocator> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::Action_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::Action_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Action_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::Action_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__Action
    std::shared_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__Action
    std::shared_ptr<rosgraph_msgs::msg::Action_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->send_goal != other.send_goal) {
      return false;
    }
    if (this->get_result != other.get_result) {
      return false;
    }
    if (this->cancel_goal != other.cancel_goal) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_

// alias to use template instance with default allocator
using Action =
  rosgraph_msgs::msg::Action_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__ACTION__STRUCT_HPP_
