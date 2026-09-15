// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from geometry_msgs:msg\VelocityWithCovarianceStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geometry_msgs/msg/velocity_with_covariance_stamped.hpp"


#ifndef GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_WITH_COVARIANCE_STAMPED__BUILDER_HPP_
#define GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_WITH_COVARIANCE_STAMPED__BUILDER_HPP_

#include <utility>

#include "geometry_msgs/msg/detail/velocity_with_covariance_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace geometry_msgs
{

namespace msg
{

namespace builder
{

class Init_VelocityWithCovarianceStamped_velocity
{
public:
  explicit Init_VelocityWithCovarianceStamped_velocity(::geometry_msgs::msg::VelocityWithCovarianceStamped & msg)
  : msg_(msg)
  {}
  ::geometry_msgs::msg::VelocityWithCovarianceStamped velocity(::geometry_msgs::msg::VelocityWithCovarianceStamped::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::geometry_msgs::msg::VelocityWithCovarianceStamped msg_;
};

class Init_VelocityWithCovarianceStamped_reference_frame_id
{
public:
  explicit Init_VelocityWithCovarianceStamped_reference_frame_id(::geometry_msgs::msg::VelocityWithCovarianceStamped & msg)
  : msg_(msg)
  {}
  Init_VelocityWithCovarianceStamped_velocity reference_frame_id(::geometry_msgs::msg::VelocityWithCovarianceStamped::_reference_frame_id_type arg)
  {
    msg_.reference_frame_id = std::move(arg);
    return Init_VelocityWithCovarianceStamped_velocity(msg_);
  }

private:
  ::geometry_msgs::msg::VelocityWithCovarianceStamped msg_;
};

class Init_VelocityWithCovarianceStamped_body_frame_id
{
public:
  explicit Init_VelocityWithCovarianceStamped_body_frame_id(::geometry_msgs::msg::VelocityWithCovarianceStamped & msg)
  : msg_(msg)
  {}
  Init_VelocityWithCovarianceStamped_reference_frame_id body_frame_id(::geometry_msgs::msg::VelocityWithCovarianceStamped::_body_frame_id_type arg)
  {
    msg_.body_frame_id = std::move(arg);
    return Init_VelocityWithCovarianceStamped_reference_frame_id(msg_);
  }

private:
  ::geometry_msgs::msg::VelocityWithCovarianceStamped msg_;
};

class Init_VelocityWithCovarianceStamped_header
{
public:
  Init_VelocityWithCovarianceStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VelocityWithCovarianceStamped_body_frame_id header(::geometry_msgs::msg::VelocityWithCovarianceStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VelocityWithCovarianceStamped_body_frame_id(msg_);
  }

private:
  ::geometry_msgs::msg::VelocityWithCovarianceStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::geometry_msgs::msg::VelocityWithCovarianceStamped>()
{
  return geometry_msgs::msg::builder::Init_VelocityWithCovarianceStamped_header();
}

}  // namespace geometry_msgs

#endif  // GEOMETRY_MSGS__MSG__DETAIL__VELOCITY_WITH_COVARIANCE_STAMPED__BUILDER_HPP_
