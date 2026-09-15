// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_interfaces:srv\SplitBagfile.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rosbag2_interfaces/srv/split_bagfile.hpp"


#ifndef ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__BUILDER_HPP_
#define ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__BUILDER_HPP_

#include <utility>

#include "rosbag2_interfaces/srv/detail/split_bagfile__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SplitBagfile_Request_tracking_topic_name
{
public:
  explicit Init_SplitBagfile_Request_tracking_topic_name(::rosbag2_interfaces::srv::SplitBagfile_Request & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::SplitBagfile_Request tracking_topic_name(::rosbag2_interfaces::srv::SplitBagfile_Request::_tracking_topic_name_type arg)
  {
    msg_.tracking_topic_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Request msg_;
};

class Init_SplitBagfile_Request_split_mode
{
public:
  explicit Init_SplitBagfile_Request_split_mode(::rosbag2_interfaces::srv::SplitBagfile_Request & msg)
  : msg_(msg)
  {}
  Init_SplitBagfile_Request_tracking_topic_name split_mode(::rosbag2_interfaces::srv::SplitBagfile_Request::_split_mode_type arg)
  {
    msg_.split_mode = std::move(arg);
    return Init_SplitBagfile_Request_tracking_topic_name(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Request msg_;
};

class Init_SplitBagfile_Request_split_time
{
public:
  Init_SplitBagfile_Request_split_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SplitBagfile_Request_split_mode split_time(::rosbag2_interfaces::srv::SplitBagfile_Request::_split_time_type arg)
  {
    msg_.split_time = std::move(arg);
    return Init_SplitBagfile_Request_split_mode(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::SplitBagfile_Request>()
{
  return rosbag2_interfaces::srv::builder::Init_SplitBagfile_Request_split_time();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SplitBagfile_Response_error_string
{
public:
  explicit Init_SplitBagfile_Response_error_string(::rosbag2_interfaces::srv::SplitBagfile_Response & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::SplitBagfile_Response error_string(::rosbag2_interfaces::srv::SplitBagfile_Response::_error_string_type arg)
  {
    msg_.error_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Response msg_;
};

class Init_SplitBagfile_Response_return_code
{
public:
  Init_SplitBagfile_Response_return_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SplitBagfile_Response_error_string return_code(::rosbag2_interfaces::srv::SplitBagfile_Response::_return_code_type arg)
  {
    msg_.return_code = std::move(arg);
    return Init_SplitBagfile_Response_error_string(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::SplitBagfile_Response>()
{
  return rosbag2_interfaces::srv::builder::Init_SplitBagfile_Response_return_code();
}

}  // namespace rosbag2_interfaces


namespace rosbag2_interfaces
{

namespace srv
{

namespace builder
{

class Init_SplitBagfile_Event_response
{
public:
  explicit Init_SplitBagfile_Event_response(::rosbag2_interfaces::srv::SplitBagfile_Event & msg)
  : msg_(msg)
  {}
  ::rosbag2_interfaces::srv::SplitBagfile_Event response(::rosbag2_interfaces::srv::SplitBagfile_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Event msg_;
};

class Init_SplitBagfile_Event_request
{
public:
  explicit Init_SplitBagfile_Event_request(::rosbag2_interfaces::srv::SplitBagfile_Event & msg)
  : msg_(msg)
  {}
  Init_SplitBagfile_Event_response request(::rosbag2_interfaces::srv::SplitBagfile_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SplitBagfile_Event_response(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Event msg_;
};

class Init_SplitBagfile_Event_info
{
public:
  Init_SplitBagfile_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SplitBagfile_Event_request info(::rosbag2_interfaces::srv::SplitBagfile_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SplitBagfile_Event_request(msg_);
  }

private:
  ::rosbag2_interfaces::srv::SplitBagfile_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_interfaces::srv::SplitBagfile_Event>()
{
  return rosbag2_interfaces::srv::builder::Init_SplitBagfile_Event_info();
}

}  // namespace rosbag2_interfaces

#endif  // ROSBAG2_INTERFACES__SRV__DETAIL__SPLIT_BAGFILE__BUILDER_HPP_
