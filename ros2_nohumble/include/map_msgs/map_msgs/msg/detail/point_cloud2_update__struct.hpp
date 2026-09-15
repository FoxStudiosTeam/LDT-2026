// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_msgs:msg\PointCloud2Update.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/point_cloud2_update.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_HPP_
#define MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_HPP_

#include <cstdint>
#include <memory>

#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'points'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_msgs__msg__PointCloud2Update __attribute__((deprecated))
#else
# define DEPRECATED__map_msgs__msg__PointCloud2Update __declspec(deprecated)
#endif

namespace map_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PointCloud2Update_
{
  using Type = PointCloud2Update_<ContainerAllocator>;

  explicit PointCloud2Update_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    points(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0ul;
    }
  }

  explicit PointCloud2Update_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    points(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _type_type =
    uint32_t;
  _type_type type;
  using _points_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__type(
    const uint32_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__points(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t ADD =
    0u;
  // guard against 'DELETE' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(DELETE)
#    pragma push_macro("DELETE")
#    undef DELETE
#  endif
#endif
  static constexpr uint32_t DELETE =
    1u;
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("DELETE")
#endif

  // pointer types
  using RawPtr =
    map_msgs::msg::PointCloud2Update_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_msgs::msg::PointCloud2Update_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::PointCloud2Update_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_msgs::msg::PointCloud2Update_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_msgs__msg__PointCloud2Update
    std::shared_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_msgs__msg__PointCloud2Update
    std::shared_ptr<map_msgs::msg::PointCloud2Update_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointCloud2Update_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointCloud2Update_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointCloud2Update_

// alias to use template instance with default allocator
using PointCloud2Update =
  map_msgs::msg::PointCloud2Update_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t PointCloud2Update_<ContainerAllocator>::ADD;
#endif  // __cplusplus < 201703L
// guard against 'DELETE' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(DELETE)
#    pragma push_macro("DELETE")
#    undef DELETE
#  endif
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t PointCloud2Update_<ContainerAllocator>::DELETE;
#endif  // __cplusplus < 201703L
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("DELETE")
#endif

}  // namespace msg

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__POINT_CLOUD2_UPDATE__STRUCT_HPP_
