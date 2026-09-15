// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_performance_benchmarking_msgs:msg\ByteArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_performance_benchmarking_msgs/msg/byte_array.hpp"


#ifndef ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_
#define ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosbag2_performance_benchmarking_msgs__msg__ByteArray __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_performance_benchmarking_msgs__msg__ByteArray __declspec(deprecated)
#endif

namespace rosbag2_performance_benchmarking_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ByteArray_
{
  using Type = ByteArray_<ContainerAllocator>;

  explicit ByteArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ByteArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_type =
    std::vector<unsigned char, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<unsigned char>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::vector<unsigned char, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<unsigned char>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_performance_benchmarking_msgs__msg__ByteArray
    std::shared_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_performance_benchmarking_msgs__msg__ByteArray
    std::shared_ptr<rosbag2_performance_benchmarking_msgs::msg::ByteArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ByteArray_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const ByteArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ByteArray_

// alias to use template instance with default allocator
using ByteArray =
  rosbag2_performance_benchmarking_msgs::msg::ByteArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_performance_benchmarking_msgs

#endif  // ROSBAG2_PERFORMANCE_BENCHMARKING_MSGS__MSG__DETAIL__BYTE_ARRAY__STRUCT_HPP_
