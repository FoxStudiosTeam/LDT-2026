@{
from rosidl_parser.definition import (
    ACTION_FEEDBACK_MESSAGE_SUFFIX,
    ACTION_FEEDBACK_SUFFIX,
    ACTION_GOAL_SERVICE_SUFFIX,
    ACTION_GOAL_SUFFIX,
    ACTION_RESULT_SERVICE_SUFFIX,
    ACTION_RESULT_SUFFIX,
    SERVICE_REQUEST_MESSAGE_SUFFIX,
    SERVICE_RESPONSE_MESSAGE_SUFFIX,
)

action_msg_specs = []

for subfolder, action in action_specs:
    action_msg_specs.append((subfolder, action.goal))
    action_msg_specs.append((subfolder, action.result))
    action_msg_specs.append((subfolder, action.feedback))
    action_msg_specs.append((subfolder, action.feedback_message))

action_srv_specs = []

for subfolder, action in action_specs:
    action_srv_specs.append((subfolder, action.send_goal_service))
    action_srv_specs.append((subfolder, action.get_result_service))
}@

#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

@{
TEMPLATE(
    'templates/msg_idiomatic.rs.em',
    package_name=package_name, interface_path=interface_path,
    msg_specs=action_msg_specs,
    get_rs_name=get_rs_name,
    get_rs_type=make_get_rs_type(True),
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)
}@

@{
TEMPLATE(
    'templates/srv_idiomatic.rs.em',
    package_name=package_name, interface_path=interface_path,
    srv_specs=action_srv_specs,
    get_rs_name=get_rs_name,
    get_rs_type=make_get_rs_type(True),
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)
}@

@[for subfolder, action_spec in action_specs]

@{
type_name = action_spec.namespaced_type.name
}@

#[link(name = "@(package_name)__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__@(package_name)__@(subfolder)__@(type_name)() -> *const std::ffi::c_void;
}

// Corresponds to @(package_name)__@(subfolder)__@(type_name)
#[allow(missing_docs, non_camel_case_types)]
pub struct @(type_name);

impl rosidl_runtime_rs::Action for @(type_name) {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = @(type_name)@(ACTION_GOAL_SUFFIX);

  /// The result message defined in the action definition.
  type Result = @(type_name)@(ACTION_RESULT_SUFFIX);

  /// The feedback message defined in the action definition.
  type Feedback = @(type_name)@(ACTION_FEEDBACK_SUFFIX);

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::@(subfolder)::@(type_name)@(ACTION_FEEDBACK_MESSAGE_SUFFIX);

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::@(subfolder)::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX);

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::@(subfolder)::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX);

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__@(package_name)__@(subfolder)__@(type_name)() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SUFFIX),
  ) -> super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX) {
   super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX) {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX),
  ) -> (
    [u8; 16],
   super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SUFFIX),
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX) {
   super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX) {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX),
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::@(subfolder)::rmw::@(type_name)@(ACTION_GOAL_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX),
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::@(subfolder)::rmw::@(type_name)@(ACTION_FEEDBACK_SUFFIX),
  ) -> super::@(subfolder)::rmw::@(type_name)@(ACTION_FEEDBACK_MESSAGE_SUFFIX) {
    let mut message = super::@(subfolder)::rmw::@(type_name)@(ACTION_FEEDBACK_MESSAGE_SUFFIX)::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::@(subfolder)::rmw::@(type_name)@(ACTION_FEEDBACK_MESSAGE_SUFFIX),
  ) -> (
    [u8; 16],
   super::@(subfolder)::rmw::@(type_name)@(ACTION_FEEDBACK_SUFFIX),
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX) {
   super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX) {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_REQUEST_MESSAGE_SUFFIX),
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SUFFIX),
  ) -> super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX) {
   super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX) {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SERVICE_SUFFIX)@(SERVICE_RESPONSE_MESSAGE_SUFFIX)
  ) -> (
    i8,
   super::@(subfolder)::rmw::@(type_name)@(ACTION_RESULT_SUFFIX),
  ) {
    (response.status, response.result)
  }
}

@[end for]
