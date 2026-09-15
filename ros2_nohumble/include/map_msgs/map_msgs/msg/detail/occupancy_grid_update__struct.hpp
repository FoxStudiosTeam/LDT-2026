// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_msgs:msg\OccupancyGridUpdate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/occupancy_grid_update.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_HPP_
#define MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <vector>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_msgs__msg__OccupancyGridUpdate __attribute__((deprecated))
#else
# define DEPRECATED__map_msgs__msg__OccupancyGridUpdate __declspec(deprecated)
#endif

namespace map_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OccupancyGridUpdate_
{
  using Type = OccupancyGridUpdate_<ContainerAllocator>;

  explicit OccupancyGridUpdate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
      this->width = 0ul;
      this->height = 0ul;
    }
  }

  explicit OccupancyGridUpdate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0l;
      this->y = 0l;
      this->width = 0ul;
      this->height = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _width_type =
    uint32_t;
  _width_type width;
  using _height_type =
    uint32_t;
  _height_type height;
  using _data_type =
    std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_msgs__msg__OccupancyGridUpdate
    std::shared_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_msgs__msg__OccupancyGridUpdate
    std::shared_ptr<map_msgs::msg::OccupancyGridUpdate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OccupancyGridUpdate_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const OccupancyGridUpdate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OccupancyGridUpdate_

// alias to use template instance with default allocator
using OccupancyGridUpdate =
  map_msgs::msg::OccupancyGridUpdate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__OCCUPANCY_GRID_UPDATE__STRUCT_HPP_
