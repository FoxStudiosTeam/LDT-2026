// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg\KeyedLong.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/keyed_long.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__KEYED_LONG__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__KEYED_LONG__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__KeyedLong __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__KeyedLong __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KeyedLong_
{
  using Type = KeyedLong_<ContainerAllocator>;

  explicit KeyedLong_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0l;
      this->value = 0l;
    }
  }

  explicit KeyedLong_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0l;
      this->value = 0l;
    }
  }

  // field types and members
  using _key_type =
    int32_t;
  _key_type key;
  using _value_type =
    int32_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__key(
    const int32_t & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__value(
    const int32_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::KeyedLong_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::KeyedLong_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::KeyedLong_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::KeyedLong_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__KeyedLong
    std::shared_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__KeyedLong
    std::shared_ptr<test_msgs::msg::KeyedLong_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KeyedLong_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const KeyedLong_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KeyedLong_

// alias to use template instance with default allocator
using KeyedLong =
  test_msgs::msg::KeyedLong_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__KEYED_LONG__STRUCT_HPP_
