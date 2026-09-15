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
    '../templates/msg_rmw.rs.em',
    package_name=package_name, interface_path=interface_path,
    msg_specs=action_msg_specs,
    get_rs_name=get_rs_name,
    get_rs_type=make_get_rs_type(False),
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)

TEMPLATE(
    '../templates/srv_rmw.rs.em',
    package_name=package_name, interface_path=interface_path,
    srv_specs=action_srv_specs,
    get_rs_name=get_rs_name,
    get_rs_type=make_get_rs_type(False),
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)
}@
