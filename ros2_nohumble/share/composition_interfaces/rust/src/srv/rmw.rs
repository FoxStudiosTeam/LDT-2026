#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__LoadNode_Request() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__LoadNode_Request__init(msg: *mut LoadNode_Request) -> bool;
    fn composition_interfaces__srv__LoadNode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Request>, size: usize) -> bool;
    fn composition_interfaces__srv__LoadNode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Request>);
    fn composition_interfaces__srv__LoadNode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadNode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Request>) -> bool;
}

// Corresponds to composition_interfaces__srv__LoadNode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadNode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub package_name: rosidl_runtime_rs::String,

    /// A plugin within the ROS package "package_name".
    pub plugin_name: rosidl_runtime_rs::String,

    /// The assigned name of the composable node. Leave empty to use the node's
    /// default name.
    pub node_name: rosidl_runtime_rs::String,

    /// The assigned namespace of the composable node. Leave empty to use the node's
    /// default namespace.
    pub node_namespace: rosidl_runtime_rs::String,

    /// The assigned log level of the composable node. Enum values are found in
    /// message rcl_interfaces/Log.
    pub log_level: u8,

    /// Remapping rules for this composable node.
    ///
    /// For more info about static_remapping rules and their syntax, see
    /// https://design.ros2.org/articles/static_remapping.html
    /// TODO(sloretz) rcl_interfaces message for remap rules?
    pub remap_rules: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// The Parameters of this composable node to set.
    pub parameters: rosidl_runtime_rs::Sequence<rcl_interfaces::msg::rmw::Parameter>,

    /// key/value arguments that are specific to a type of container process.
    pub extra_arguments: rosidl_runtime_rs::Sequence<rcl_interfaces::msg::rmw::Parameter>,

}



impl Default for LoadNode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__LoadNode_Request__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__LoadNode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadNode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadNode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadNode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/LoadNode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__LoadNode_Request() }
  }
}


#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__LoadNode_Response() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__LoadNode_Response__init(msg: *mut LoadNode_Response) -> bool;
    fn composition_interfaces__srv__LoadNode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Response>, size: usize) -> bool;
    fn composition_interfaces__srv__LoadNode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Response>);
    fn composition_interfaces__srv__LoadNode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LoadNode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<LoadNode_Response>) -> bool;
}

// Corresponds to composition_interfaces__srv__LoadNode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadNode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// Human readable error message if success is false, else empty string.
    pub error_message: rosidl_runtime_rs::String,

    /// Name of the loaded composable node (including namespace).
    pub full_node_name: rosidl_runtime_rs::String,

    /// A unique identifier for the loaded node.
    pub unique_id: u64,

}



impl Default for LoadNode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__LoadNode_Response__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__LoadNode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LoadNode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__LoadNode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LoadNode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LoadNode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/LoadNode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__LoadNode_Response() }
  }
}


#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__ListNodes_Request() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__ListNodes_Request__init(msg: *mut ListNodes_Request) -> bool;
    fn composition_interfaces__srv__ListNodes_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Request>, size: usize) -> bool;
    fn composition_interfaces__srv__ListNodes_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Request>);
    fn composition_interfaces__srv__ListNodes_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ListNodes_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Request>) -> bool;
}

// Corresponds to composition_interfaces__srv__ListNodes_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListNodes_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ListNodes_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__ListNodes_Request__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__ListNodes_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ListNodes_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ListNodes_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ListNodes_Request where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/ListNodes_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__ListNodes_Request() }
  }
}


#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__ListNodes_Response() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__ListNodes_Response__init(msg: *mut ListNodes_Response) -> bool;
    fn composition_interfaces__srv__ListNodes_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Response>, size: usize) -> bool;
    fn composition_interfaces__srv__ListNodes_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Response>);
    fn composition_interfaces__srv__ListNodes_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ListNodes_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ListNodes_Response>) -> bool;
}

// Corresponds to composition_interfaces__srv__ListNodes_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListNodes_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub full_node_names: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

    /// corresponding unique ids (must have same length as full_node_names).
    pub unique_ids: rosidl_runtime_rs::Sequence<u64>,

}



impl Default for ListNodes_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__ListNodes_Response__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__ListNodes_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ListNodes_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__ListNodes_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ListNodes_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ListNodes_Response where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/ListNodes_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__ListNodes_Response() }
  }
}


#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__UnloadNode_Request() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__UnloadNode_Request__init(msg: *mut UnloadNode_Request) -> bool;
    fn composition_interfaces__srv__UnloadNode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Request>, size: usize) -> bool;
    fn composition_interfaces__srv__UnloadNode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Request>);
    fn composition_interfaces__srv__UnloadNode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UnloadNode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Request>) -> bool;
}

// Corresponds to composition_interfaces__srv__UnloadNode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnloadNode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub unique_id: u64,

}



impl Default for UnloadNode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__UnloadNode_Request__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__UnloadNode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UnloadNode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UnloadNode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UnloadNode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/UnloadNode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__UnloadNode_Request() }
  }
}


#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__UnloadNode_Response() -> *const std::ffi::c_void;
}

#[link(name = "composition_interfaces__rosidl_generator_c")]
extern "C" {
    fn composition_interfaces__srv__UnloadNode_Response__init(msg: *mut UnloadNode_Response) -> bool;
    fn composition_interfaces__srv__UnloadNode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Response>, size: usize) -> bool;
    fn composition_interfaces__srv__UnloadNode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Response>);
    fn composition_interfaces__srv__UnloadNode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UnloadNode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<UnloadNode_Response>) -> bool;
}

// Corresponds to composition_interfaces__srv__UnloadNode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnloadNode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// Human readable error message if success is false, else empty string.
    pub error_message: rosidl_runtime_rs::String,

}



impl Default for UnloadNode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !composition_interfaces__srv__UnloadNode_Response__init(&mut msg as *mut _) {
        panic!("Call to composition_interfaces__srv__UnloadNode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UnloadNode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { composition_interfaces__srv__UnloadNode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UnloadNode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UnloadNode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "composition_interfaces/srv/UnloadNode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__composition_interfaces__srv__UnloadNode_Response() }
  }
}






#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__LoadNode() -> *const std::ffi::c_void;
}

// Corresponds to composition_interfaces__srv__LoadNode
#[allow(missing_docs, non_camel_case_types)]
pub struct LoadNode;

impl rosidl_runtime_rs::Service for LoadNode {
    type Request = LoadNode_Request;
    type Response = LoadNode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__LoadNode() }
    }
}




#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__ListNodes() -> *const std::ffi::c_void;
}

// Corresponds to composition_interfaces__srv__ListNodes
#[allow(missing_docs, non_camel_case_types)]
pub struct ListNodes;

impl rosidl_runtime_rs::Service for ListNodes {
    type Request = ListNodes_Request;
    type Response = ListNodes_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__ListNodes() }
    }
}




#[link(name = "composition_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__UnloadNode() -> *const std::ffi::c_void;
}

// Corresponds to composition_interfaces__srv__UnloadNode
#[allow(missing_docs, non_camel_case_types)]
pub struct UnloadNode;

impl rosidl_runtime_rs::Service for UnloadNode {
    type Request = UnloadNode_Request;
    type Response = UnloadNode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__composition_interfaces__srv__UnloadNode() }
    }
}


