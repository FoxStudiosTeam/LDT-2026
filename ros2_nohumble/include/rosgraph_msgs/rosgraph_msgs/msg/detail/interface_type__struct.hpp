// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\InterfaceType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/interface_type.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'hash'
#include "rosgraph_msgs/msg/detail/type_hash__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__InterfaceType __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__InterfaceType __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InterfaceType_
{
  using Type = InterfaceType_<ContainerAllocator>;

  explicit InterfaceType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hash(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit InterfaceType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    hash(_alloc, _init)
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
  using _hash_type =
    rosgraph_msgs::msg::TypeHash_<ContainerAllocator>;
  _hash_type hash;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__hash(
    const rosgraph_msgs::msg::TypeHash_<ContainerAllocator> & _arg)
  {
    this->hash = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__InterfaceType
    std::shared_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__InterfaceType
    std::shared_ptr<rosgraph_msgs::msg::InterfaceType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InterfaceType_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->hash != other.hash) {
      return false;
    }
    return true;
  }
  bool operator!=(const InterfaceType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InterfaceType_

// alias to use template instance with default allocator
using InterfaceType =
  rosgraph_msgs::msg::InterfaceType_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__INTERFACE_TYPE__STRUCT_HPP_
