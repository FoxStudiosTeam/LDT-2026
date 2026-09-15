// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\Play.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/play.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/play__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Play_Request_playback_until_timestamp
{
public:
  explicit Init_Play_Request_playback_until_timestamp(::rosbag2_interfaces::srv::Play_Request & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Play_Request playback_until_timestamp(::rosbag2_interfaces::srv::Play_Request::_playback_until_timestamp_type arg)
  {
    msg_.playback_until_timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Request msg_;
};

class Init_Play_Request_playback_duration
{
public:
  explicit Init_Play_Request_playback_duration(::rosbag2_interfaces::srv::Play_Request & msg)
  : msg_(msg)
  {}
  Init_Play_Request_playback_until_timestamp playback_duration(::rosbag2_interfaces::srv::Play_Request::_playback_duration_type arg)
  {
    msg_.playback_duration = std::move(arg);
    return Init_Play_Request_playback_until_timestamp(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Request msg_;
};

class Init_Play_Request_start_offset
{
public:
  Init_Play_Request_start_offset()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Play_Request_playback_duration start_offset(::rosbag2_interfaces::srv::Play_Request::_start_offset_type arg)
  {
    msg_.start_offset = std::move(arg);
    return Init_Play_Request_playback_duration(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Play_Request>()
{
  return rosbag2_interfaces::srv::builder::Init_Play_Request_start_offset();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Play_Response_success
{
public:
  Init_Play_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_interfaces::srv::Play_Response success(::rosbag2_interfaces::srv::Play_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Play_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_Play_Response_success();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_Play_Event_response
{
public:
  explicit Init_Play_Event_response(::rosbag2_interfaces::srv::Play_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::Play_Event response(::rosbag2_interfaces::srv::Play_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Event msg_;
};

class Init_Play_Event_request
{
public:
  explicit Init_Play_Event_request(::rosbag2_interfaces::srv::Play_Event & msg)
  : msg_(msg)
  {}
  Init_Play_Event_response request(::rosbag2_interfaces::srv::Play_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Play_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Event msg_;
};

class Init_Play_Event_info
{
public:
  Init_Play_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Play_Event_request info(::rosbag2_interfaces::srv::Play_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Play_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::Play_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::Play_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_Play_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__PLAY__BUILDER_HPP_
