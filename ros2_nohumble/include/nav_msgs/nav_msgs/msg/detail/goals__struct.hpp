// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nav_msgs:msg\Goals.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "nav_msgs/msg/goals.hpp"


#ifndef NAV_MSGS__MSG__DETAIL__GOALS__STRUCT_HPP_
#define NAV_MSGS__MSG__DETAIL__GOALS__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'goals'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nav_msgs__msg__Goals __attribute__((deprecated))
#else
# define DEPRECATED__nav_msgs__msg__Goals __declspec(deprecated)
#endif

namespace nav_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Goals_
{
  using Type = Goals_<ContainerAllocator>;

  explicit Goals_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Goals_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _goals_type =
    std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>>;
  _goals_type goals;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__goals(
    const std::vector<geometry_msgs::msg::PoseStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PoseStamped_<ContainerAllocator>>> & _arg)
  {
    this->goals = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nav_msgs::msg::Goals_<ContainerAllocator> *;
  using ConstRawPtr =
    const nav_msgs::msg::Goals_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nav_msgs::msg::Goals_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nav_msgs::msg::Goals_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nav_msgs::msg::Goals_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nav_msgs::msg::Goals_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nav_msgs::msg::Goals_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nav_msgs::msg::Goals_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nav_msgs::msg::Goals_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nav_msgs::msg::Goals_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nav_msgs__msg__Goals
    std::shared_ptr<nav_msgs::msg::Goals_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nav_msgs__msg__Goals
    std::shared_ptr<nav_msgs::msg::Goals_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Goals_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->goals != other.goals) {
      return false;
    }
    return true;
  }
  bool operator!=(const Goals_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Goals_

// alias to use template instance with default allocator
using Goals =
  nav_msgs::msg::Goals_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nav_msgs

#endif  // NAV_MSGS__MSG__DETAIL__GOALS__STRUCT_HPP_
