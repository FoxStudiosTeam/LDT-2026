// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosgraph_msgs:msg\TypeHash.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosgraph_msgs/msg/type_hash.hpp"


#ifndef ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__STRUCT_HPP_
#define ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosgraph_msgs__msg__TypeHash __attribute__((deprecated))
#else
# define DEPRECATED__rosgraph_msgs__msg__TypeHash __declspec(deprecated)
#endif

namespace rosgraph_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TypeHash_
{
  using Type = TypeHash_<ContainerAllocator>;

  explicit TypeHash_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->version = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->version = 0;
      std::fill(this->value.begin(), this->value.end(), 0);
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill(this->value.begin(), this->value.end(), 0);
    }
  }

  explicit TypeHash_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->version = 1;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->version = 0;
      std::fill(this->value.begin(), this->value.end(), 0);
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill(this->value.begin(), this->value.end(), 0);
    }
  }

  // field types and members
  using _version_type =
    uint8_t;
  _version_type version;
  using _value_type =
    std::array<uint8_t, 32>;
  _value_type value;

  // setters for named parameter idiom
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__value(
    const std::array<uint8_t, 32> & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosgraph_msgs::msg::TypeHash_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosgraph_msgs::msg::TypeHash_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::TypeHash_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosgraph_msgs::msg::TypeHash_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosgraph_msgs__msg__TypeHash
    std::shared_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosgraph_msgs__msg__TypeHash
    std::shared_ptr<rosgraph_msgs::msg::TypeHash_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TypeHash_ & other) const
  {
    if (this->version != other.version) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const TypeHash_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TypeHash_

// alias to use template instance with default allocator
using TypeHash =
  rosgraph_msgs::msg::TypeHash_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosgraph_msgs

#endif  // ROSGRAPH_MSGS__MSG__DETAIL__TYPE_HASH__STRUCT_HPP_
