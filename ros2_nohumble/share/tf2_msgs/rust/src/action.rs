
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tf2_msgs__action__LookupTransform_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_frame: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_frame: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_time: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub timeout: builtin_interfaces::msg::Duration,

    /// Advanced API
    pub target_time: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fixed_frame: std::string::String,

    /// Whether or not to use the advanced API
    pub advanced: bool,

}



impl Default for LookupTransform_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_Goal {
  type RmwMsg = super::action::rmw::LookupTransform_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_frame: msg.target_frame.as_str().into(),
        source_frame: msg.source_frame.as_str().into(),
        source_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.source_time)).into_owned(),
        timeout: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Owned(msg.timeout)).into_owned(),
        target_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.target_time)).into_owned(),
        fixed_frame: msg.fixed_frame.as_str().into(),
        advanced: msg.advanced,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_frame: msg.target_frame.as_str().into(),
        source_frame: msg.source_frame.as_str().into(),
        source_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.source_time)).into_owned(),
        timeout: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Borrowed(&msg.timeout)).into_owned(),
        target_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.target_time)).into_owned(),
        fixed_frame: msg.fixed_frame.as_str().into(),
      advanced: msg.advanced,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_frame: msg.target_frame.to_string(),
      source_frame: msg.source_frame.to_string(),
      source_time: builtin_interfaces::msg::Time::from_rmw_message(msg.source_time),
      timeout: builtin_interfaces::msg::Duration::from_rmw_message(msg.timeout),
      target_time: builtin_interfaces::msg::Time::from_rmw_message(msg.target_time),
      fixed_frame: msg.fixed_frame.to_string(),
      advanced: msg.advanced,
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transform: geometry_msgs::msg::TransformStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: super::msg::TF2Error,

}



impl Default for LookupTransform_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_Result::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_Result {
  type RmwMsg = super::action::rmw::LookupTransform_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transform: geometry_msgs::msg::TransformStamped::into_rmw_message(std::borrow::Cow::Owned(msg.transform)).into_owned(),
        error: super::msg::TF2Error::into_rmw_message(std::borrow::Cow::Owned(msg.error)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transform: geometry_msgs::msg::TransformStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.transform)).into_owned(),
        error: super::msg::TF2Error::into_rmw_message(std::borrow::Cow::Borrowed(&msg.error)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transform: geometry_msgs::msg::TransformStamped::from_rmw_message(msg.transform),
      error: super::msg::TF2Error::from_rmw_message(msg.error),
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for LookupTransform_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_Feedback {
  type RmwMsg = super::action::rmw::LookupTransform_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::LookupTransform_Feedback,

}



impl Default for LookupTransform_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_FeedbackMessage {
  type RmwMsg = super::action::rmw::LookupTransform_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::LookupTransform_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::LookupTransform_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::LookupTransform_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to tf2_msgs__action__LookupTransform_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::LookupTransform_Goal,

}



impl Default for LookupTransform_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_SendGoal_Request {
  type RmwMsg = super::action::rmw::LookupTransform_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::LookupTransform_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::LookupTransform_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::LookupTransform_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for LookupTransform_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_SendGoal_Response {
  type RmwMsg = super::action::rmw::LookupTransform_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for LookupTransform_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_GetResult_Request {
  type RmwMsg = super::action::rmw::LookupTransform_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to tf2_msgs__action__LookupTransform_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LookupTransform_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::LookupTransform_Result,

}



impl Default for LookupTransform_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::LookupTransform_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for LookupTransform_GetResult_Response {
  type RmwMsg = super::action::rmw::LookupTransform_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::LookupTransform_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::LookupTransform_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::LookupTransform_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__action__LookupTransform_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to tf2_msgs__action__LookupTransform_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct LookupTransform_SendGoal;

impl rosidl_runtime_rs::Service for LookupTransform_SendGoal {
    type Request = LookupTransform_SendGoal_Request;
    type Response = LookupTransform_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__action__LookupTransform_SendGoal() }
    }
}




#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__action__LookupTransform_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to tf2_msgs__action__LookupTransform_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct LookupTransform_GetResult;

impl rosidl_runtime_rs::Service for LookupTransform_GetResult {
    type Request = LookupTransform_GetResult_Request;
    type Response = LookupTransform_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__tf2_msgs__action__LookupTransform_GetResult() }
    }
}






#[link(name = "tf2_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__tf2_msgs__action__LookupTransform() -> *const std::ffi::c_void;
}

// Corresponds to tf2_msgs__action__LookupTransform
#[allow(missing_docs, non_camel_case_types)]
pub struct LookupTransform;

impl rosidl_runtime_rs::Action for LookupTransform {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = LookupTransform_Goal;

  /// The result message defined in the action definition.
  type Result = LookupTransform_Result;

  /// The feedback message defined in the action definition.
  type Feedback = LookupTransform_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::LookupTransform_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::LookupTransform_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::LookupTransform_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__tf2_msgs__action__LookupTransform() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::LookupTransform_Goal,
  ) -> super::action::rmw::LookupTransform_SendGoal_Request {
   super::action::rmw::LookupTransform_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::LookupTransform_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::LookupTransform_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::LookupTransform_SendGoal_Response {
   super::action::rmw::LookupTransform_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::LookupTransform_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::LookupTransform_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::LookupTransform_Feedback,
  ) -> super::action::rmw::LookupTransform_FeedbackMessage {
    let mut message = super::action::rmw::LookupTransform_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::LookupTransform_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::LookupTransform_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::LookupTransform_GetResult_Request {
   super::action::rmw::LookupTransform_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::LookupTransform_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::LookupTransform_Result,
  ) -> super::action::rmw::LookupTransform_GetResult_Response {
   super::action::rmw::LookupTransform_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::LookupTransform_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::LookupTransform_Result,
  ) {
    (response.status, response.result)
  }
}


