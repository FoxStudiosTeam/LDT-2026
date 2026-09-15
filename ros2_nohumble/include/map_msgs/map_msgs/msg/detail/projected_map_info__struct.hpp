// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map_info.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_HPP_

#include <cstdint>
#include <memory>
#include <string>

#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__map_msgs__msg__ProjectedMapInfo __attribute__((deprecated))
#else
# define DEPRECATED__map_msgs__msg__ProjectedMapInfo __declspec(deprecated)
#endif

namespace map_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProjectedMapInfo_
{
  using Type = ProjectedMapInfo_<ContainerAllocator>;

  explicit ProjectedMapInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->width = 0.0;
      this->height = 0.0;
      this->min_z = 0.0;
      this->max_z = 0.0;
    }
  }

  explicit ProjectedMapInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->width = 0.0;
      this->height = 0.0;
      this->min_z = 0.0;
      this->max_z = 0.0;
    }
  }

  // field types and members
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_id_type frame_id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _width_type =
    double;
  _width_type width;
  using _height_type =
    double;
  _height_type height;
  using _min_z_type =
    double;
  _min_z_type min_z;
  using _max_z_type =
    double;
  _max_z_type max_z;

  // setters for named parameter idiom
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__width(
    const double & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__min_z(
    const double & _arg)
  {
    this->min_z = _arg;
    return *this;
  }
  Type & set__max_z(
    const double & _arg)
  {
    this->max_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_msgs__msg__ProjectedMapInfo
    std::shared_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_msgs__msg__ProjectedMapInfo
    std::shared_ptr<map_msgs::msg::ProjectedMapInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProjectedMapInfo_ & other) const
  {
    if (this->frame_id != other.frame_id) {
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
    if (this->min_z != other.min_z) {
      return false;
    }
    if (this->max_z != other.max_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProjectedMapInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProjectedMapInfo_

// alias to use template instance with default allocator
using ProjectedMapInfo =
  map_msgs::msg::ProjectedMapInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__STRUCT_HPP_
