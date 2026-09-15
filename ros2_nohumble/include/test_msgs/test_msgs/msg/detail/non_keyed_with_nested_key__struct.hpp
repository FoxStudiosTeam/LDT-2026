// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg\NonKeyedWithNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/non_keyed_with_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'nested_data'
#include "test_msgs/msg/detail/keyed_string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__NonKeyedWithNestedKey __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__NonKeyedWithNestedKey __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NonKeyedWithNestedKey_
{
  using Type = NonKeyedWithNestedKey_<ContainerAllocator>;

  explicit NonKeyedWithNestedKey_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nested_data(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->some_int = 0l;
    }
  }

  explicit NonKeyedWithNestedKey_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nested_data(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->some_int = 0l;
    }
  }

  // field types and members
  using _nested_data_type =
    test_msgs::msg::KeyedString_<ContainerAllocator>;
  _nested_data_type nested_data;
  using _some_int_type =
    int32_t;
  _some_int_type some_int;

  // setters for named parameter idiom
  Type & set__nested_data(
    const test_msgs::msg::KeyedString_<ContainerAllocator> & _arg)
  {
    this->nested_data = _arg;
    return *this;
  }
  Type & set__some_int(
    const int32_t & _arg)
  {
    this->some_int = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__NonKeyedWithNestedKey
    std::shared_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__NonKeyedWithNestedKey
    std::shared_ptr<test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NonKeyedWithNestedKey_ & other) const
  {
    if (this->nested_data != other.nested_data) {
      return false;
    }
    if (this->some_int != other.some_int) {
      return false;
    }
    return true;
  }
  bool operator!=(const NonKeyedWithNestedKey_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NonKeyedWithNestedKey_

// alias to use template instance with default allocator
using NonKeyedWithNestedKey =
  test_msgs::msg::NonKeyedWithNestedKey_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__NON_KEYED_WITH_NESTED_KEY__STRUCT_HPP_
