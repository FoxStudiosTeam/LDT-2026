#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to composition_interfaces__srv__LoadNode_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadNode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub package_name: std::string::String,

    /// A plugin within the ROS package "package_name".
    pub plugin_name: std::string::String,

    /// The assigned name of the composable node. Leave empty to use the node's
    /// default name.
    pub node_name: std::string::String,

    /// The assigned namespace of the composable node. Leave empty to use the node's
    /// default namespace.
    pub node_namespace: std::string::String,

    /// The assigned log level of the composable node. Enum values are found in
    /// message rcl_interfaces/Log.
    pub log_level: u8,

    /// Remapping rules for this composable node.
    ///
    /// For more info about static_remapping rules and their syntax, see
    /// https://design.ros2.org/articles/static_remapping.html
    /// TODO(sloretz) rcl_interfaces message for remap rules?
    pub remap_rules: Vec<std::string::String>,

    /// The Parameters of this composable node to set.
    pub parameters: Vec<rcl_interfaces::msg::Parameter>,

    /// key/value arguments that are specific to a type of container process.
    pub extra_arguments: Vec<rcl_interfaces::msg::Parameter>,

}



impl Default for LoadNode_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::LoadNode_Request::default())
  }
}

impl rosidl_runtime_rs::Message for LoadNode_Request {
  type RmwMsg = super::srv::rmw::LoadNode_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        package_name: msg.package_name.as_str().into(),
        plugin_name: msg.plugin_name.as_str().into(),
        node_name: msg.node_name.as_str().into(),
        node_namespace: msg.node_namespace.as_str().into(),
        log_level: msg.log_level,
        remap_rules: msg.remap_rules
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        parameters: msg.parameters
          .into_iter()
          .map(|elem| rcl_interfaces::msg::Parameter::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        extra_arguments: msg.extra_arguments
          .into_iter()
          .map(|elem| rcl_interfaces::msg::Parameter::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        package_name: msg.package_name.as_str().into(),
        plugin_name: msg.plugin_name.as_str().into(),
        node_name: msg.node_name.as_str().into(),
        node_namespace: msg.node_namespace.as_str().into(),
      log_level: msg.log_level,
        remap_rules: msg.remap_rules
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        parameters: msg.parameters
          .iter()
          .map(|elem| rcl_interfaces::msg::Parameter::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        extra_arguments: msg.extra_arguments
          .iter()
          .map(|elem| rcl_interfaces::msg::Parameter::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      package_name: msg.package_name.to_string(),
      plugin_name: msg.plugin_name.to_string(),
      node_name: msg.node_name.to_string(),
      node_namespace: msg.node_namespace.to_string(),
      log_level: msg.log_level,
      remap_rules: msg.remap_rules
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      parameters: msg.parameters
          .into_iter()
          .map(rcl_interfaces::msg::Parameter::from_rmw_message)
          .collect(),
      extra_arguments: msg.extra_arguments
          .into_iter()
          .map(rcl_interfaces::msg::Parameter::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to composition_interfaces__srv__LoadNode_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadNode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// Human readable error message if success is false, else empty string.
    pub error_message: std::string::String,

    /// Name of the loaded composable node (including namespace).
    pub full_node_name: std::string::String,

    /// A unique identifier for the loaded node.
    pub unique_id: u64,

}



impl Default for LoadNode_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::LoadNode_Response::default())
  }
}

impl rosidl_runtime_rs::Message for LoadNode_Response {
  type RmwMsg = super::srv::rmw::LoadNode_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error_message: msg.error_message.as_str().into(),
        full_node_name: msg.full_node_name.as_str().into(),
        unique_id: msg.unique_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error_message: msg.error_message.as_str().into(),
        full_node_name: msg.full_node_name.as_str().into(),
      unique_id: msg.unique_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error_message: msg.error_message.to_string(),
      full_node_name: msg.full_node_name.to_string(),
      unique_id: msg.unique_id,
    }
  }
}


// Corresponds to composition_interfaces__srv__ListNodes_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListNodes_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ListNodes_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ListNodes_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ListNodes_Request {
  type RmwMsg = super::srv::rmw::ListNodes_Request;

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


// Corresponds to composition_interfaces__srv__ListNodes_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ListNodes_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub full_node_names: Vec<std::string::String>,

    /// corresponding unique ids (must have same length as full_node_names).
    pub unique_ids: Vec<u64>,

}



impl Default for ListNodes_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ListNodes_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ListNodes_Response {
  type RmwMsg = super::srv::rmw::ListNodes_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        full_node_names: msg.full_node_names
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        unique_ids: msg.unique_ids.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        full_node_names: msg.full_node_names
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        unique_ids: msg.unique_ids.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      full_node_names: msg.full_node_names
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      unique_ids: msg.unique_ids.into(),
    }
  }
}


// Corresponds to composition_interfaces__srv__UnloadNode_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnloadNode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub unique_id: u64,

}



impl Default for UnloadNode_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::UnloadNode_Request::default())
  }
}

impl rosidl_runtime_rs::Message for UnloadNode_Request {
  type RmwMsg = super::srv::rmw::UnloadNode_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        unique_id: msg.unique_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      unique_id: msg.unique_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      unique_id: msg.unique_id,
    }
  }
}


// Corresponds to composition_interfaces__srv__UnloadNode_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UnloadNode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

    /// Human readable error message if success is false, else empty string.
    pub error_message: std::string::String,

}



impl Default for UnloadNode_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::UnloadNode_Response::default())
  }
}

impl rosidl_runtime_rs::Message for UnloadNode_Response {
  type RmwMsg = super::srv::rmw::UnloadNode_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error_message: msg.error_message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error_message: msg.error_message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error_message: msg.error_message.to_string(),
    }
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


