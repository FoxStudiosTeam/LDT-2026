// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_test_msgdefs:msg\BasicMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_test_msgdefs/msg/basic_msg.hpp"


#ifndef ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_HPP_
#define ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosbag2_test_msgdefs__msg__BasicMsg __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_test_msgdefs__msg__BasicMsg __declspec(deprecated)
#endif

namespace rosbag2_test_msgdefs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BasicMsg_
{
  using Type = BasicMsg_<ContainerAllocator>;

  explicit BasicMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0.0f;
    }
  }

  explicit BasicMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0.0f;
    }
  }

  // field types and members
  using _c_type =
    float;
  _c_type c;

  // setters for named parameter idiom
  Type & set__c(
    const float & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__BasicMsg
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_test_msgdefs__msg__BasicMsg
    std::shared_ptr<rosbag2_test_msgdefs::msg::BasicMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BasicMsg_ & other) const
  {
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const BasicMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BasicMsg_

// alias to use template instance with default allocator
using BasicMsg =
  rosbag2_test_msgdefs::msg::BasicMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_test_msgdefs

#endif  // ROSBAG2_TEST_MSGDEFS__MSG__DETAIL__BASIC_MSG__STRUCT_HPP_
