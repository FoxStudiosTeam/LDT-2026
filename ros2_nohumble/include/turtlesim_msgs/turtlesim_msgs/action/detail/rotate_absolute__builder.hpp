// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtlesim_msgs:action\RotateAbsolute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtlesim_msgs/action/rotate_absolute.hpp"


#ifndef TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__BUILDER_HPP_
#define TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__BUILDER_HPP_

#include <utility>

#include "turtlesim_msgs/action/detail/rotate_absolute__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_Goal_theta
{
public:
  Init_RotateAbsolute_Goal_theta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_Goal theta(::turtlesim_msgs::action::RotateAbsolute_Goal::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_Goal>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_Goal_theta();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_Result_delta
{
public:
  Init_RotateAbsolute_Result_delta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_Result delta(::turtlesim_msgs::action::RotateAbsolute_Result::_delta_type arg)
  {
    msg_.delta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_Result>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_Result_delta();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_Feedback_remaining
{
public:
  Init_RotateAbsolute_Feedback_remaining()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_Feedback remaining(::turtlesim_msgs::action::RotateAbsolute_Feedback::_remaining_type arg)
  {
    msg_.remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_Feedback>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_Feedback_remaining();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_SendGoal_Request_goal
{
public:
  explicit Init_RotateAbsolute_SendGoal_Request_goal(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request goal(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request msg_;
};

class Init_RotateAbsolute_SendGoal_Request_goal_id
{
public:
  Init_RotateAbsolute_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_SendGoal_Request_goal goal_id(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RotateAbsolute_SendGoal_Request_goal(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_SendGoal_Request>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_SendGoal_Request_goal_id();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_SendGoal_Response_stamp
{
public:
  explicit Init_RotateAbsolute_SendGoal_Response_stamp(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response stamp(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response msg_;
};

class Init_RotateAbsolute_SendGoal_Response_accepted
{
public:
  Init_RotateAbsolute_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_SendGoal_Response_stamp accepted(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RotateAbsolute_SendGoal_Response_stamp(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_SendGoal_Response>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_SendGoal_Response_accepted();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_SendGoal_Event_response
{
public:
  explicit Init_RotateAbsolute_SendGoal_Event_response(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event response(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event msg_;
};

class Init_RotateAbsolute_SendGoal_Event_request
{
public:
  explicit Init_RotateAbsolute_SendGoal_Event_request(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_RotateAbsolute_SendGoal_Event_response request(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RotateAbsolute_SendGoal_Event_response(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event msg_;
};

class Init_RotateAbsolute_SendGoal_Event_info
{
public:
  Init_RotateAbsolute_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_SendGoal_Event_request info(::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RotateAbsolute_SendGoal_Event_request(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_SendGoal_Event>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_SendGoal_Event_info();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_GetResult_Request_goal_id
{
public:
  Init_RotateAbsolute_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Request goal_id(::turtlesim_msgs::action::RotateAbsolute_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_GetResult_Request>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_GetResult_Request_goal_id();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_GetResult_Response_result
{
public:
  explicit Init_RotateAbsolute_GetResult_Response_result(::turtlesim_msgs::action::RotateAbsolute_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Response result(::turtlesim_msgs::action::RotateAbsolute_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Response msg_;
};

class Init_RotateAbsolute_GetResult_Response_status
{
public:
  Init_RotateAbsolute_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_GetResult_Response_result status(::turtlesim_msgs::action::RotateAbsolute_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RotateAbsolute_GetResult_Response_result(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_GetResult_Response>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_GetResult_Response_status();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_GetResult_Event_response
{
public:
  explicit Init_RotateAbsolute_GetResult_Event_response(::turtlesim_msgs::action::RotateAbsolute_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Event response(::turtlesim_msgs::action::RotateAbsolute_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Event msg_;
};

class Init_RotateAbsolute_GetResult_Event_request
{
public:
  explicit Init_RotateAbsolute_GetResult_Event_request(::turtlesim_msgs::action::RotateAbsolute_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_RotateAbsolute_GetResult_Event_response request(::turtlesim_msgs::action::RotateAbsolute_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RotateAbsolute_GetResult_Event_response(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Event msg_;
};

class Init_RotateAbsolute_GetResult_Event_info
{
public:
  Init_RotateAbsolute_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_GetResult_Event_request info(::turtlesim_msgs::action::RotateAbsolute_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RotateAbsolute_GetResult_Event_request(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_GetResult_Event>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_GetResult_Event_info();
}

}  // namespace turtlesim_msgs


namespace turtlesim_msgs
{

namespace action
{

namespace builder
{

class Init_RotateAbsolute_FeedbackMessage_feedback
{
public:
  explicit Init_RotateAbsolute_FeedbackMessage_feedback(::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage feedback(::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage msg_;
};

class Init_RotateAbsolute_FeedbackMessage_goal_id
{
public:
  Init_RotateAbsolute_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateAbsolute_FeedbackMessage_feedback goal_id(::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RotateAbsolute_FeedbackMessage_feedback(msg_);
  }

private:
  ::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtlesim_msgs::action::RotateAbsolute_FeedbackMessage>()
{
  return turtlesim_msgs::action::builder::Init_RotateAbsolute_FeedbackMessage_goal_id();
}

}  // namespace turtlesim_msgs

#endif  // TURTLESIM_MSGS__ACTION__DETAIL__ROTATE_ABSOLUTE__BUILDER_HPP_
