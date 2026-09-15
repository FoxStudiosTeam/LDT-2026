// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\PlayNext.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/play_next.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__PLAY_NEXT__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__PLAY_NEXT__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/play_next__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::PlayNext_Request>()
{
  return ::rosbag2_interfaces::srv::PlayNext_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_PlayNext_Response_success
{
public:
  Init_PlayNext_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_interfaces::srv::PlayNext_Response success(::rosbag2_interfaces::srv::PlayNext_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::PlayNext_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::PlayNext_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_PlayNext_Response_success();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_PlayNext_Event_response
{
public:
  explicit Init_PlayNext_Event_response(::rosbag2_interfaces::srv::PlayNext_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::PlayNext_Event response(::rosbag2_interfaces::srv::PlayNext_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::PlayNext_Event msg_;
};

class Init_PlayNext_Event_request
{
public:
  explicit Init_PlayNext_Event_request(::rosbag2_interfaces::srv::PlayNext_Event & msg)
  : msg_(msg)
  {}
  Init_PlayNext_Event_response request(::rosbag2_interfaces::srv::PlayNext_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PlayNext_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::PlayNext_Event msg_;
};

class Init_PlayNext_Event_info
{
public:
  Init_PlayNext_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlayNext_Event_request info(::rosbag2_interfaces::srv::PlayNext_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PlayNext_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::PlayNext_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::PlayNext_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_PlayNext_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__PLAY_NEXT__BUILDER_HPP_
