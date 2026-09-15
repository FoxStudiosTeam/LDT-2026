// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:srv\Empty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "test_msgs/srv/empty.hpp"


#ifndef TEST_MSGS__SRV__DETAIL__EMPTY__BUILDER_HPP_
#define TEST_MSGS__SRV__DETAIL__EMPTY__BUILDER_HPP_

#include <utility>

#include "test_msgs/srv/detail/empty__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::srv::Empty_Request>()
{
  return ::test_msgs::srv::Empty_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace test_msgs


namespace test_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::srv::Empty_Response>()
{
  return ::test_msgs::srv::Empty_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace test_msgs


namespace test_msgs
{

namespace srv
{

namespace builder
{

class Init_Empty_Event_response
{
public:
  explicit Init_Empty_Event_response(::test_msgs::srv::Empty_Event & msg)
  : msg_(msg)
  {}
  ::test_msgs::srv::Empty_Event response(::test_msgs::srv::Empty_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::srv::Empty_Event msg_;
};

class Init_Empty_Event_request
{
public:
  explicit Init_Empty_Event_request(::test_msgs::srv::Empty_Event & msg)
  : msg_(msg)
  {}
  Init_Empty_Event_response request(::test_msgs::srv::Empty_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Empty_Event_response(msg_);
  }

private:
  ::test_msgs::srv::Empty_Event msg_;
};

class Init_Empty_Event_info
{
public:
  Init_Empty_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Empty_Event_request info(::test_msgs::srv::Empty_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Empty_Event_request(msg_);
  }

private:
  ::test_msgs::srv::Empty_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::srv::Empty_Event>()
{
  return test_msgs::srv::builder::Init_Empty_Event_info();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__SRV__DETAIL__EMPTY__BUILDER_HPP_
