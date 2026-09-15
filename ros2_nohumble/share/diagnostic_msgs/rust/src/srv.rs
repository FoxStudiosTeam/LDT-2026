#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to diagnostic_msgs__srv__AddDiagnostics_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddDiagnostics_Request {
    /// The load_namespace parameter defines the namespace where parameters for the
    /// initialization of analyzers in the diagnostic aggregator have been loaded. The
    /// value should be a global name (i.e. /my/name/space), not a relative
    /// (my/name/space) or private (~my/name/space) name. Analyzers will not be added
    /// if a non-global name is used. The call will also fail if the namespace
    /// contains parameters that follow a namespace structure that does not conform to
    /// that expected by the analyzer definitions. See
    /// http://wiki.ros.org/diagnostics/Tutorials/Configuring%20Diagnostic%20Aggregators
    /// and http://wiki.ros.org/diagnostics/Tutorials/Using%20the%20GenericAnalyzer
    /// for examples of the structure of yaml files which are expected to have been
    /// loaded into the namespace.
    pub load_namespace: std::string::String,

}



impl Default for AddDiagnostics_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AddDiagnostics_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AddDiagnostics_Request {
  type RmwMsg = super::srv::rmw::AddDiagnostics_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_namespace: msg.load_namespace.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_namespace: msg.load_namespace.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      load_namespace: msg.load_namespace.to_string(),
    }
  }
}


// Corresponds to diagnostic_msgs__srv__AddDiagnostics_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddDiagnostics_Response {
    /// True if diagnostic aggregator was updated with new diagnostics, False
    /// otherwise. A false return value means that either there is a bond in the
    /// aggregator which already used the requested namespace, or the initialization
    /// of analyzers failed.
    pub success: bool,

    /// Message with additional information about the success or failure
    pub message: std::string::String,

}



impl Default for AddDiagnostics_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AddDiagnostics_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AddDiagnostics_Response {
  type RmwMsg = super::srv::rmw::AddDiagnostics_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to diagnostic_msgs__srv__SelfTest_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SelfTest_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SelfTest_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SelfTest_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SelfTest_Request {
  type RmwMsg = super::srv::rmw::SelfTest_Request;

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


// Corresponds to diagnostic_msgs__srv__SelfTest_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SelfTest_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub passed: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: Vec<super::msg::DiagnosticStatus>,

}



impl Default for SelfTest_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SelfTest_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SelfTest_Response {
  type RmwMsg = super::srv::rmw::SelfTest_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
        passed: msg.passed,
        status: msg.status
          .into_iter()
          .map(|elem| super::msg::DiagnosticStatus::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
      passed: msg.passed,
        status: msg.status
          .iter()
          .map(|elem| super::msg::DiagnosticStatus::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id.to_string(),
      passed: msg.passed,
      status: msg.status
          .into_iter()
          .map(super::msg::DiagnosticStatus::from_rmw_message)
          .collect(),
    }
  }
}






#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__diagnostic_msgs__srv__AddDiagnostics() -> *const std::ffi::c_void;
}

// Corresponds to diagnostic_msgs__srv__AddDiagnostics
#[allow(missing_docs, non_camel_case_types)]
pub struct AddDiagnostics;

impl rosidl_runtime_rs::Service for AddDiagnostics {
    type Request = AddDiagnostics_Request;
    type Response = AddDiagnostics_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__diagnostic_msgs__srv__AddDiagnostics() }
    }
}




#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__diagnostic_msgs__srv__SelfTest() -> *const std::ffi::c_void;
}

// Corresponds to diagnostic_msgs__srv__SelfTest
#[allow(missing_docs, non_camel_case_types)]
pub struct SelfTest;

impl rosidl_runtime_rs::Service for SelfTest {
    type Request = SelfTest_Request;
    type Response = SelfTest_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__diagnostic_msgs__srv__SelfTest() }
    }
}


