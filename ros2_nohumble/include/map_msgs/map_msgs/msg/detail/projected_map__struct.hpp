// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'map'
#include "nav_msgs/msg/detail/occupancy_grid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_msgs__msg__ProjectedMap __attribute__((deprecated))
#else
# define DEPRECATED__map_msgs__msg__ProjectedMap __declspec(deprecated)
#endif

namespace map_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProjectedMap_
{
  using Type = ProjectedMap_<ContainerAllocator>;

  explicit ProjectedMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : map(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_z = 0.0;
      this->max_z = 0.0;
    }
  }

  explicit ProjectedMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : map(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_z = 0.0;
      this->max_z = 0.0;
    }
  }

  // field types and members
  using _map_type =
    nav_msgs::msg::OccupancyGrid_<ContainerAllocator>;
  _map_type map;
  using _min_z_type =
    double;
  _min_z_type min_z;
  using _max_z_type =
    double;
  _max_z_type max_z;

  // setters for named parameter idiom
  Type & set__map(
    const nav_msgs::msg::OccupancyGrid_<ContainerAllocator> & _arg)
  {
    this->map = _arg;
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
    map_msgs::msg::ProjectedMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_msgs::msg::ProjectedMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::ProjectedMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::ProjectedMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_msgs__msg__ProjectedMap
    std::shared_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_msgs__msg__ProjectedMap
    std::shared_ptr<map_msgs::msg::ProjectedMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProjectedMap_ & other) const
  {
    if (this->map != other.map) {
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
  bool operator!=(const ProjectedMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProjectedMap_

// alias to use template instance with default allocator
using ProjectedMap =
  map_msgs::msg::ProjectedMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__STRUCT_HPP_
