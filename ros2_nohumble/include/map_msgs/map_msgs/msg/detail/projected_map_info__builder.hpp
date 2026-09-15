// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_msgs:msg\ProjectedMapInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "map_msgs/msg/projected_map_info.hpp"


#ifndef MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__BUILDER_HPP_
#define MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__BUILDER_HPP_

#include <utility>

#include "map_msgs/msg/detail/projected_map_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_msgs
{

namespace msg
{

namespace builder
{

class Init_ProjectedMapInfo_max_z
{
public:
  explicit Init_ProjectedMapInfo_max_z(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  ::map_msgs::msg::ProjectedMapInfo max_z(::map_msgs::msg::ProjectedMapInfo::_max_z_type arg)
  {
    msg_.max_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_min_z
{
public:
  explicit Init_ProjectedMapInfo_min_z(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapInfo_max_z min_z(::map_msgs::msg::ProjectedMapInfo::_min_z_type arg)
  {
    msg_.min_z = std::move(arg);
    return Init_ProjectedMapInfo_max_z(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_height
{
public:
  explicit Init_ProjectedMapInfo_height(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapInfo_min_z height(::map_msgs::msg::ProjectedMapInfo::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ProjectedMapInfo_min_z(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_width
{
public:
  explicit Init_ProjectedMapInfo_width(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapInfo_height width(::map_msgs::msg::ProjectedMapInfo::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ProjectedMapInfo_height(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_y
{
public:
  explicit Init_ProjectedMapInfo_y(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapInfo_width y(::map_msgs::msg::ProjectedMapInfo::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ProjectedMapInfo_width(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_x
{
public:
  explicit Init_ProjectedMapInfo_x(::map_msgs::msg::ProjectedMapInfo & msg)
  : msg_(msg)
  {}
  Init_ProjectedMapInfo_y x(::map_msgs::msg::ProjectedMapInfo::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ProjectedMapInfo_y(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

class Init_ProjectedMapInfo_frame_id
{
public:
  Init_ProjectedMapInfo_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProjectedMapInfo_x frame_id(::map_msgs::msg::ProjectedMapInfo::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_ProjectedMapInfo_x(msg_);
  }

private:
  ::map_msgs::msg::ProjectedMapInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_msgs::msg::ProjectedMapInfo>()
{
  return map_msgs::msg::builder::Init_ProjectedMapInfo_frame_id();
}

}  // namespace map_msgs

#endif  // MAP_MSGS__MSG__DETAIL__PROJECTED_MAP_INFO__BUILDER_HPP_
