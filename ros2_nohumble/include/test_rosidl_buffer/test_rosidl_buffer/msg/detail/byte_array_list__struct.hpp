// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_rosidl_buffer:msg\ByteArrayList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_rosidl_buffer/msg/byte_array_list.hpp"


#ifndef TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_HPP_
#define TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'items'
#include "test_rosidl_buffer/msg/detail/byte_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__test_rosidl_buffer__msg__ByteArrayList __attribute__((deprecated))
#else
# define DEPRECATED__test_rosidl_buffer__msg__ByteArrayList __declspec(deprecated)
#endif

namespace test_rosidl_buffer
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ByteArrayList_
{
  using Type = ByteArrayList_<ContainerAllocator>;

  explicit ByteArrayList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ByteArrayList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _items_type =
    std::vector<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>>;
  _items_type items;

  // setters for named parameter idiom
  Type & set__items(
    const std::vector<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<test_rosidl_buffer::msg::ByteArray_<ContainerAllocator>>> & _arg)
  {
    this->items = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_rosidl_buffer__msg__ByteArrayList
    std::shared_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_rosidl_buffer__msg__ByteArrayList
    std::shared_ptr<test_rosidl_buffer::msg::ByteArrayList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ByteArrayList_ & other) const
  {
    if (this->items != other.items) {
      return false;
    }
    return true;
  }
  bool operator!=(const ByteArrayList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ByteArrayList_

// alias to use template instance with default allocator
using ByteArrayList =
  test_rosidl_buffer::msg::ByteArrayList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_rosidl_buffer

#endif  // TEST_ROSIDL_BUFFER__MSG__DETAIL__BYTE_ARRAY_LIST__STRUCT_HPP_
