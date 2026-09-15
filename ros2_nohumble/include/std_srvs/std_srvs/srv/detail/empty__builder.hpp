// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from std_srvs:srv\Empty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "std_srvs/srv/empty.hpp"


#ifndef STD_SRVS__SRV__DETAIL__EMPTY__BUILDER_HPP_
#define STD_SRVS__SRV__DETAIL__EMPTY__BUILDER_HPP_

#include <utility>

#include "std_srvs/srv/detail/empty__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace std_srvs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::std_srvs::srv::Empty_Request>()
{
  return ::std_srvs::srv::Empty_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace std_srvs


namespace std_srvs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::std_srvs::srv::Empty_Response>()
{
  return ::std_srvs::srv::Empty_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace std_srvs


namespace std_srvs
{

namespace srv
{

namespace builder
{

class Init_Empty_Event_response
{
public:
  explicit Init_Empty_Event_response(::std_srvs::srv::Empty_Event & msg)
  : msg_(msg)
  {}
  ::std_srvs::srv::Empty_Event response(::std_srvs::srv::Empty_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::std_srvs::srv::Empty_Event msg_;
};

class Init_Empty_Event_request
{
public:
  explicit Init_Empty_Event_request(::std_srvs::srv::Empty_Event & msg)
  : msg_(msg)
  {}
  Init_Empty_Event_response request(::std_srvs::srv::Empty_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Empty_Event_response(msg_);
  }

private:
  ::std_srvs::srv::Empty_Event msg_;
};

class Init_Empty_Event_info
{
public:
  Init_Empty_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Empty_Event_request info(::std_srvs::srv::Empty_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Empty_Event_request(msg_);
  }

private:
  ::std_srvs::srv::Empty_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::std_srvs::srv::Empty_Event>()
{
  return std_srvs::srv::builder::Init_Empty_Event_info();
}

}  // namespace std_srvs

#endif  // STD_SRVS__SRV__DETAIL__EMPTY__BUILDER_HPP_
