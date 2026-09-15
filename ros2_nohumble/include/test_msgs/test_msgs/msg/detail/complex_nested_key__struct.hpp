// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg\ComplexNestedKey.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/msg/complex_nested_key.hpp"


#ifndef TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'nested_keys'
#include "test_msgs/msg/detail/non_keyed_with_nested_key__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__ComplexNestedKey __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__ComplexNestedKey __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ComplexNestedKey_
{
  using Type = ComplexNestedKey_<ContainerAllocator>;

  explicit ComplexNestedKey_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nested_keys(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uint32_key = 0ul;
      this->float64_value = 0.0;
    }
  }

  explicit ComplexNestedKey_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nested_keys(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uint32_key = 0ul;
      this->float64_value = 0.0;
    }
  }

  // field types and members
  using _uint32_key_type =
    uint32_t;
  _uint32_key_type uint32_key;
  using _nested_keys_type =
    test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator>;
  _nested_keys_type nested_keys;
  using _float64_value_type =
    double;
  _float64_value_type float64_value;

  // setters for named parameter idiom
  Type & set__uint32_key(
    const uint32_t & _arg)
  {
    this->uint32_key = _arg;
    return *this;
  }
  Type & set__nested_keys(
    const test_msgs::msg::NonKeyedWithNestedKey_<ContainerAllocator> & _arg)
  {
    this->nested_keys = _arg;
    return *this;
  }
  Type & set__float64_value(
    const double & _arg)
  {
    this->float64_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::ComplexNestedKey_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::ComplexNestedKey_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::ComplexNestedKey_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::ComplexNestedKey_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__ComplexNestedKey
    std::shared_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__ComplexNestedKey
    std::shared_ptr<test_msgs::msg::ComplexNestedKey_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexNestedKey_ & other) const
  {
    if (this->uint32_key != other.uint32_key) {
      return false;
    }
    if (this->nested_keys != other.nested_keys) {
      return false;
    }
    if (this->float64_value != other.float64_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComplexNestedKey_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexNestedKey_

// alias to use template instance with default allocator
using ComplexNestedKey =
  test_msgs::msg::ComplexNestedKey_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__COMPLEX_NESTED_KEY__STRUCT_HPP_
