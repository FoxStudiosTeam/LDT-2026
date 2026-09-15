// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:msg\ProjectedMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__BUILDER_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__BUILDER_HPP_

#include <utility>

#include "map_msgs/msg/detail/projected_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace msg
{

namespace builder
{

class Init_ProjectedMap_max_z
{
public:
  explicit Init_ProjectedMap_max_z(::map_msgs::msg::ProjectedMap & msg)
  : msg_(msg)
  {}
  ::map_msgs::msg::ProjectedMap max_z(::map_msgs::msg::ProjectedMap::_max_z_type arg)
  {
    msg_.max_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMap msg_;
};

class Init_ProjectedMap_min_z
{
public:
  explicit Init_ProjectedMap_min_z(::map_msgs::msg::ProjectedMap & msg)
  : msg_(msg)
  {}
  Init_ProjectedMap_max_z min_z(::map_msgs::msg::ProjectedMap::_min_z_type arg)
  {
    msg_.min_z = std::move(arg);
    return Init_ProjectedMap_max_z(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMap msg_;
};

class Init_ProjectedMap_map
{
public:
  Init_ProjectedMap_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProjectedMap_min_z map(::map_msgs::msg::ProjectedMap::_map_type arg)
  {
    msg_.map = std::move(arg);
    return Init_ProjectedMap_min_z(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::msg::ProjectedMap>()
{
  return map_msgs::msg::builder::Init_ProjectedMap_map();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP__BUILDER_HPP_
