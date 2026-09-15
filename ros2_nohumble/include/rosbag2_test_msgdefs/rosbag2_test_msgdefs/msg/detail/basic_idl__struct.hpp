// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_test_msgdefs:msg\BasicIdl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/basic_idl.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__msg__BasicIdl __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__msg__BasicIdl __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BasicIdl_
{
  using Type = BasicIdl_<ContainerAllocator>;

  explicit BasicIdl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
    }
  }

  explicit BasicIdl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__BasicIdl
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__BasicIdl
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicIdl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BasicIdl_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    return true;
  }
  bool operator!=(const BasicIdl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BasicIdl_

// alias to use template instance with default allocator
using BasicIdl =
  rosbag2_test_msgdefs::msg::BasicIdl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_IDL__STRUCT_HPP_
