#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to lifecycle_msgs__srv__ChangeState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChangeState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transition: super::msg::Transition,

}



impl Default for ChangeState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ChangeState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ChangeState_Request {
  type RmwMsg = super::srv::rmw::ChangeState_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Owned(msg.transition)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transition: super::msg::Transition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.transition)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transition: super::msg::Transition::from_rmw_message(msg.transition),
    }
  }
}


// Corresponds to lifecycle_msgs__srv__ChangeState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChangeState_Response {
    /// Indicates whether the service was able to initiate the state transition
    pub success: bool,

}



impl Default for ChangeState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ChangeState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ChangeState_Response {
  type RmwMsg = super::srv::rmw::ChangeState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to lifecycle_msgs__srv__GetAvailableStates_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableStates_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetAvailableStates_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetAvailableStates_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetAvailableStates_Request {
  type RmwMsg = super::srv::rmw::GetAvailableStates_Request;

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


// Corresponds to lifecycle_msgs__srv__GetAvailableStates_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableStates_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub available_states: Vec<super::msg::State>,

}



impl Default for GetAvailableStates_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetAvailableStates_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetAvailableStates_Response {
  type RmwMsg = super::srv::rmw::GetAvailableStates_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        available_states: msg.available_states
          .into_iter()
          .map(|elem| super::msg::State::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        available_states: msg.available_states
          .iter()
          .map(|elem| super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      available_states: msg.available_states
          .into_iter()
          .map(super::msg::State::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableTransitions_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetAvailableTransitions_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetAvailableTransitions_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetAvailableTransitions_Request {
  type RmwMsg = super::srv::rmw::GetAvailableTransitions_Request;

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


// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetAvailableTransitions_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub available_transitions: Vec<super::msg::TransitionDescription>,

}



impl Default for GetAvailableTransitions_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetAvailableTransitions_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetAvailableTransitions_Response {
  type RmwMsg = super::srv::rmw::GetAvailableTransitions_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        available_transitions: msg.available_transitions
          .into_iter()
          .map(|elem| super::msg::TransitionDescription::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        available_transitions: msg.available_transitions
          .iter()
          .map(|elem| super::msg::TransitionDescription::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      available_transitions: msg.available_transitions
          .into_iter()
          .map(super::msg::TransitionDescription::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to lifecycle_msgs__srv__GetState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetState_Request {
  type RmwMsg = super::srv::rmw::GetState_Request;

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


// Corresponds to lifecycle_msgs__srv__GetState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_state: super::msg::State,

}



impl Default for GetState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetState_Response {
  type RmwMsg = super::srv::rmw::GetState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_state: super::msg::State::into_rmw_message(std::borrow::Cow::Owned(msg.current_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_state: super::msg::State::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      current_state: super::msg::State::from_rmw_message(msg.current_state),
    }
  }
}






#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__ChangeState() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__ChangeState
#[allow(missing_docs, non_camel_case_types)]
pub struct ChangeState;

impl rosidl_runtime_rs::Service for ChangeState {
    type Request = ChangeState_Request;
    type Response = ChangeState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__ChangeState() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableStates() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableStates
#[allow(missing_docs, non_camel_case_types)]
pub struct GetAvailableStates;

impl rosidl_runtime_rs::Service for GetAvailableStates {
    type Request = GetAvailableStates_Request;
    type Response = GetAvailableStates_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableStates() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetAvailableTransitions
#[allow(missing_docs, non_camel_case_types)]
pub struct GetAvailableTransitions;

impl rosidl_runtime_rs::Service for GetAvailableTransitions {
    type Request = GetAvailableTransitions_Request;
    type Response = GetAvailableTransitions_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetAvailableTransitions() }
    }
}




#[link(name = "lifecycle_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetState() -> *const std::ffi::c_void;
}

// Corresponds to lifecycle_msgs__srv__GetState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetState;

impl rosidl_runtime_rs::Service for GetState {
    type Request = GetState_Request;
    type Response = GetState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__lifecycle_msgs__srv__GetState() }
    }
}


