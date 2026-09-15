#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__AddDiagnostics_Request() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__srv__AddDiagnostics_Request__init(msg: *mut AddDiagnostics_Request) -> bool;
    fn diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Request>, size: usize) -> bool;
    fn diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Request>);
    fn diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddDiagnostics_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Request>) -> bool;
}

// Corresponds to diagnostic_msgs__srv__AddDiagnostics_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub load_namespace: rosidl_runtime_rs::String,

}



impl Default for AddDiagnostics_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__srv__AddDiagnostics_Request__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__srv__AddDiagnostics_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddDiagnostics_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddDiagnostics_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddDiagnostics_Request where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/srv/AddDiagnostics_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__AddDiagnostics_Request() }
  }
}


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__AddDiagnostics_Response() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__srv__AddDiagnostics_Response__init(msg: *mut AddDiagnostics_Response) -> bool;
    fn diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Response>, size: usize) -> bool;
    fn diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Response>);
    fn diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddDiagnostics_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AddDiagnostics_Response>) -> bool;
}

// Corresponds to diagnostic_msgs__srv__AddDiagnostics_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddDiagnostics_Response {
    /// True if diagnostic aggregator was updated with new diagnostics, False
    /// otherwise. A false return value means that either there is a bond in the
    /// aggregator which already used the requested namespace, or the initialization
    /// of analyzers failed.
    pub success: bool,

    /// Message with additional information about the success or failure
    pub message: rosidl_runtime_rs::String,

}



impl Default for AddDiagnostics_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__srv__AddDiagnostics_Response__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__srv__AddDiagnostics_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddDiagnostics_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__AddDiagnostics_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddDiagnostics_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddDiagnostics_Response where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/srv/AddDiagnostics_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__AddDiagnostics_Response() }
  }
}


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__SelfTest_Request() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__srv__SelfTest_Request__init(msg: *mut SelfTest_Request) -> bool;
    fn diagnostic_msgs__srv__SelfTest_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Request>, size: usize) -> bool;
    fn diagnostic_msgs__srv__SelfTest_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Request>);
    fn diagnostic_msgs__srv__SelfTest_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SelfTest_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Request>) -> bool;
}

// Corresponds to diagnostic_msgs__srv__SelfTest_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SelfTest_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SelfTest_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__srv__SelfTest_Request__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__srv__SelfTest_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SelfTest_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SelfTest_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SelfTest_Request where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/srv/SelfTest_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__SelfTest_Request() }
  }
}


#[link(name = "diagnostic_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__SelfTest_Response() -> *const std::ffi::c_void;
}

#[link(name = "diagnostic_msgs__rosidl_generator_c")]
extern "C" {
    fn diagnostic_msgs__srv__SelfTest_Response__init(msg: *mut SelfTest_Response) -> bool;
    fn diagnostic_msgs__srv__SelfTest_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Response>, size: usize) -> bool;
    fn diagnostic_msgs__srv__SelfTest_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Response>);
    fn diagnostic_msgs__srv__SelfTest_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SelfTest_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SelfTest_Response>) -> bool;
}

// Corresponds to diagnostic_msgs__srv__SelfTest_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SelfTest_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub passed: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: rosidl_runtime_rs::Sequence<super::super::msg::rmw::DiagnosticStatus>,

}



impl Default for SelfTest_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !diagnostic_msgs__srv__SelfTest_Response__init(&mut msg as *mut _) {
        panic!("Call to diagnostic_msgs__srv__SelfTest_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SelfTest_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { diagnostic_msgs__srv__SelfTest_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SelfTest_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SelfTest_Response where Self: Sized {
  const TYPE_NAME: &'static str = "diagnostic_msgs/srv/SelfTest_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__diagnostic_msgs__srv__SelfTest_Response() }
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


