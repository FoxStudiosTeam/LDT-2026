#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to rosbag2_interfaces__srv__Burst_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Burst_Request {
    /// Number of messages to burst; zero to burst the whole bag
    pub num_messages: u64,

}



impl Default for Burst_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Burst_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Burst_Request {
  type RmwMsg = super::srv::rmw::Burst_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        num_messages: msg.num_messages,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      num_messages: msg.num_messages,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      num_messages: msg.num_messages,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Burst_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Burst_Response {
    /// Number of messages actually burst
    pub actually_burst: u64,

}



impl Default for Burst_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Burst_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Burst_Response {
  type RmwMsg = super::srv::rmw::Burst_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        actually_burst: msg.actually_burst,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      actually_burst: msg.actually_burst,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      actually_burst: msg.actually_burst,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__GetRate_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRate_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRate_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRate_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetRate_Request {
  type RmwMsg = super::srv::rmw::GetRate_Request;

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


// Corresponds to rosbag2_interfaces__srv__GetRate_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRate_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub rate: f64,

}



impl Default for GetRate_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRate_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetRate_Response {
  type RmwMsg = super::srv::rmw::GetRate_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        rate: msg.rate,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      rate: msg.rate,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      rate: msg.rate,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSubscribedTopics_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetSubscribedTopics_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSubscribedTopics_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetSubscribedTopics_Request {
  type RmwMsg = super::srv::rmw::GetSubscribedTopics_Request;

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


// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSubscribedTopics_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub topics: Vec<std::string::String>,

}



impl Default for GetSubscribedTopics_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSubscribedTopics_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetSubscribedTopics_Response {
  type RmwMsg = super::srv::rmw::GetSubscribedTopics_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        topics: msg.topics
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        topics: msg.topics
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      topics: msg.topics
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsDiscoveryRunning_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsDiscoveryRunning_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsDiscoveryRunning_Request::default())
  }
}

impl rosidl_runtime_rs::Message for IsDiscoveryRunning_Request {
  type RmwMsg = super::srv::rmw::IsDiscoveryRunning_Request;

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


// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsDiscoveryRunning_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub running: bool,

}



impl Default for IsDiscoveryRunning_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsDiscoveryRunning_Response::default())
  }
}

impl rosidl_runtime_rs::Message for IsDiscoveryRunning_Response {
  type RmwMsg = super::srv::rmw::IsDiscoveryRunning_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        running: msg.running,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      running: msg.running,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      running: msg.running,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__IsPaused_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsPaused_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsPaused_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsPaused_Request::default())
  }
}

impl rosidl_runtime_rs::Message for IsPaused_Request {
  type RmwMsg = super::srv::rmw::IsPaused_Request;

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


// Corresponds to rosbag2_interfaces__srv__IsPaused_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsPaused_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub paused: bool,

}



impl Default for IsPaused_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsPaused_Response::default())
  }
}

impl rosidl_runtime_rs::Message for IsPaused_Response {
  type RmwMsg = super::srv::rmw::IsPaused_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        paused: msg.paused,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      paused: msg.paused,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      paused: msg.paused,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Pause_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Pause_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Pause_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Pause_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Pause_Request {
  type RmwMsg = super::srv::rmw::Pause_Request;

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


// Corresponds to rosbag2_interfaces__srv__Pause_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Pause_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Pause_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Pause_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Pause_Response {
  type RmwMsg = super::srv::rmw::Pause_Response;

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


// Corresponds to rosbag2_interfaces__srv__Play_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Play_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_offset: builtin_interfaces::msg::Time,

    /// See rosbag2_transport::PlayOptions::playback_duration
    pub playback_duration: builtin_interfaces::msg::Duration,

    /// See rosbag2_transport::PlayOptions::playback_until_timestamp
    pub playback_until_timestamp: builtin_interfaces::msg::Time,

}



impl Default for Play_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Play_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Play_Request {
  type RmwMsg = super::srv::rmw::Play_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_offset: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.start_offset)).into_owned(),
        playback_duration: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Owned(msg.playback_duration)).into_owned(),
        playback_until_timestamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.playback_until_timestamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_offset: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_offset)).into_owned(),
        playback_duration: builtin_interfaces::msg::Duration::into_rmw_message(std::borrow::Cow::Borrowed(&msg.playback_duration)).into_owned(),
        playback_until_timestamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.playback_until_timestamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start_offset: builtin_interfaces::msg::Time::from_rmw_message(msg.start_offset),
      playback_duration: builtin_interfaces::msg::Duration::from_rmw_message(msg.playback_duration),
      playback_until_timestamp: builtin_interfaces::msg::Time::from_rmw_message(msg.playback_until_timestamp),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Play_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Play_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Play_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Play_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Play_Response {
  type RmwMsg = super::srv::rmw::Play_Response;

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


// Corresponds to rosbag2_interfaces__srv__PlayNext_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlayNext_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for PlayNext_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PlayNext_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PlayNext_Request {
  type RmwMsg = super::srv::rmw::PlayNext_Request;

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


// Corresponds to rosbag2_interfaces__srv__PlayNext_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlayNext_Response {
    /// can only play-next while playback is paused
    pub success: bool,

}



impl Default for PlayNext_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PlayNext_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PlayNext_Response {
  type RmwMsg = super::srv::rmw::PlayNext_Response;

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


// Corresponds to rosbag2_interfaces__srv__Record_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Record_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub uri: std::string::String,

    /// Timestamp in the future when to start recording.
    /// If empty or time in the past, recording starts immediately.
    pub start_time: builtin_interfaces::msg::Time,

}



impl Default for Record_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Record_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Record_Request {
  type RmwMsg = super::srv::rmw::Record_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        uri: msg.uri.as_str().into(),
        start_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.start_time)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        uri: msg.uri.as_str().into(),
        start_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_time)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      uri: msg.uri.to_string(),
      start_time: builtin_interfaces::msg::Time::from_rmw_message(msg.start_time),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Record_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Record_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}



impl Default for Record_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Record_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Record_Response {
  type RmwMsg = super::srv::rmw::Record_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Resume_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Resume_Request {
    /// Timestamp in the future when to resume recording/playback.
    /// If empty or time in the past, resumes recording/playback immediately.
    /// Note: The resume_time is not supported by player and shall be set to zero when using Resume with
    /// player.
    pub resume_time: builtin_interfaces::msg::Time,

    /// Resume mode to use for the resume_time request.
    pub resume_mode: i32,

    /// Topic name to use for timestamp-based resume evaluation.
    /// If empty, evaluate using messages from all topics.
    pub tracking_topic_name: std::string::String,

}

impl Resume_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_NODE_TIME: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_PUBLISH_TIME: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RESUME_MODE_RECEIVE_TIME: i32 = 2;

}


impl Default for Resume_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Resume_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Resume_Request {
  type RmwMsg = super::srv::rmw::Resume_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resume_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.resume_time)).into_owned(),
        resume_mode: msg.resume_mode,
        tracking_topic_name: msg.tracking_topic_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        resume_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.resume_time)).into_owned(),
      resume_mode: msg.resume_mode,
        tracking_topic_name: msg.tracking_topic_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      resume_time: builtin_interfaces::msg::Time::from_rmw_message(msg.resume_time),
      resume_mode: msg.resume_mode,
      tracking_topic_name: msg.tracking_topic_name.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Resume_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Resume_Response {
    /// Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}

impl Resume_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SUCCESS: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_RESUME_MODE: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_TRACKING_TOPIC: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_RESUME_FAILED: i32 = 3;

}


impl Default for Resume_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Resume_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Resume_Response {
  type RmwMsg = super::srv::rmw::Resume_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Seek_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Seek_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub time: builtin_interfaces::msg::Time,

}



impl Default for Seek_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Seek_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Seek_Request {
  type RmwMsg = super::srv::rmw::Seek_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.time)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.time)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      time: builtin_interfaces::msg::Time::from_rmw_message(msg.time),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Seek_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Seek_Response {
    /// return true if valid time in bag duration, and successful seek
    pub success: bool,

}



impl Default for Seek_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Seek_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Seek_Response {
  type RmwMsg = super::srv::rmw::Seek_Response;

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


// Corresponds to rosbag2_interfaces__srv__SetRate_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRate_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub rate: f64,

}



impl Default for SetRate_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetRate_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetRate_Request {
  type RmwMsg = super::srv::rmw::SetRate_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        rate: msg.rate,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      rate: msg.rate,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      rate: msg.rate,
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__SetRate_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRate_Response {
    /// true if valid rate (> 0) was set
    pub success: bool,

}



impl Default for SetRate_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetRate_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetRate_Response {
  type RmwMsg = super::srv::rmw::SetRate_Response;

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


// Corresponds to rosbag2_interfaces__srv__Snapshot_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Snapshot_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Snapshot_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Snapshot_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Snapshot_Request {
  type RmwMsg = super::srv::rmw::Snapshot_Request;

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


// Corresponds to rosbag2_interfaces__srv__Snapshot_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Snapshot_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Snapshot_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Snapshot_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Snapshot_Response {
  type RmwMsg = super::srv::rmw::Snapshot_Response;

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


// Corresponds to rosbag2_interfaces__srv__SplitBagfile_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SplitBagfile_Request {
    /// Timestamp in the future when to split bag file.
    /// If empty or time in the past, split bag file immediately.
    pub split_time: builtin_interfaces::msg::Time,

    /// Split mode to use for the split_time request.
    pub split_mode: i32,

    /// Topic name to use for timestamp-based split evaluation.
    /// If empty, evaluate using messages from all topics.
    pub tracking_topic_name: std::string::String,

}

impl SplitBagfile_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_NODE_TIME: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_PUBLISH_TIME: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPLIT_MODE_RECEIVE_TIME: i32 = 2;

}


impl Default for SplitBagfile_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SplitBagfile_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SplitBagfile_Request {
  type RmwMsg = super::srv::rmw::SplitBagfile_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        split_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.split_time)).into_owned(),
        split_mode: msg.split_mode,
        tracking_topic_name: msg.tracking_topic_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        split_time: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.split_time)).into_owned(),
      split_mode: msg.split_mode,
        tracking_topic_name: msg.tracking_topic_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      split_time: builtin_interfaces::msg::Time::from_rmw_message(msg.split_time),
      split_mode: msg.split_mode,
      tracking_topic_name: msg.tracking_topic_name.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__SplitBagfile_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SplitBagfile_Response {
    /// Return code. Use RETURN_CODE_SUCCESS on success; otherwise use one of the error codes.
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}

impl SplitBagfile_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SUCCESS: i32 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_NOT_RECORDING: i32 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_SPLIT_MODE: i32 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_INVALID_TRACKING_TOPIC: i32 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RETURN_CODE_SPLIT_FAILED: i32 = 4;

}


impl Default for SplitBagfile_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SplitBagfile_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SplitBagfile_Response {
  type RmwMsg = super::srv::rmw::SplitBagfile_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__StartDiscovery_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartDiscovery_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for StartDiscovery_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StartDiscovery_Request::default())
  }
}

impl rosidl_runtime_rs::Message for StartDiscovery_Request {
  type RmwMsg = super::srv::rmw::StartDiscovery_Request;

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


// Corresponds to rosbag2_interfaces__srv__StartDiscovery_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StartDiscovery_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}



impl Default for StartDiscovery_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StartDiscovery_Response::default())
  }
}

impl rosidl_runtime_rs::Message for StartDiscovery_Response {
  type RmwMsg = super::srv::rmw::StartDiscovery_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__Stop_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Stop_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Stop_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Stop_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Stop_Request {
  type RmwMsg = super::srv::rmw::Stop_Request;

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


// Corresponds to rosbag2_interfaces__srv__Stop_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Stop_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}



impl Default for Stop_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Stop_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Stop_Response {
  type RmwMsg = super::srv::rmw::Stop_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__StopDiscovery_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopDiscovery_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for StopDiscovery_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StopDiscovery_Request::default())
  }
}

impl rosidl_runtime_rs::Message for StopDiscovery_Request {
  type RmwMsg = super::srv::rmw::StopDiscovery_Request;

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


// Corresponds to rosbag2_interfaces__srv__StopDiscovery_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopDiscovery_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub return_code: i32,

    /// Error string. Empty if no error occurred.
    pub error_string: std::string::String,

}



impl Default for StopDiscovery_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StopDiscovery_Response::default())
  }
}

impl rosidl_runtime_rs::Message for StopDiscovery_Response {
  type RmwMsg = super::srv::rmw::StopDiscovery_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      return_code: msg.return_code,
        error_string: msg.error_string.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      return_code: msg.return_code,
      error_string: msg.error_string.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__srv__TogglePaused_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TogglePaused_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for TogglePaused_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TogglePaused_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TogglePaused_Request {
  type RmwMsg = super::srv::rmw::TogglePaused_Request;

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


// Corresponds to rosbag2_interfaces__srv__TogglePaused_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TogglePaused_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for TogglePaused_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TogglePaused_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TogglePaused_Response {
  type RmwMsg = super::srv::rmw::TogglePaused_Response;

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






#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Burst() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Burst
#[allow(missing_docs, non_camel_case_types)]
pub struct Burst;

impl rosidl_runtime_rs::Service for Burst {
    type Request = Burst_Request;
    type Response = Burst_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Burst() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetRate() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__GetRate
#[allow(missing_docs, non_camel_case_types)]
pub struct GetRate;

impl rosidl_runtime_rs::Service for GetRate {
    type Request = GetRate_Request;
    type Response = GetRate_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetRate() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__GetSubscribedTopics
#[allow(missing_docs, non_camel_case_types)]
pub struct GetSubscribedTopics;

impl rosidl_runtime_rs::Service for GetSubscribedTopics {
    type Request = GetSubscribedTopics_Request;
    type Response = GetSubscribedTopics_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__GetSubscribedTopics() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__IsDiscoveryRunning
#[allow(missing_docs, non_camel_case_types)]
pub struct IsDiscoveryRunning;

impl rosidl_runtime_rs::Service for IsDiscoveryRunning {
    type Request = IsDiscoveryRunning_Request;
    type Response = IsDiscoveryRunning_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsDiscoveryRunning() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsPaused() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__IsPaused
#[allow(missing_docs, non_camel_case_types)]
pub struct IsPaused;

impl rosidl_runtime_rs::Service for IsPaused {
    type Request = IsPaused_Request;
    type Response = IsPaused_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__IsPaused() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Pause() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Pause
#[allow(missing_docs, non_camel_case_types)]
pub struct Pause;

impl rosidl_runtime_rs::Service for Pause {
    type Request = Pause_Request;
    type Response = Pause_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Pause() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Play() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Play
#[allow(missing_docs, non_camel_case_types)]
pub struct Play;

impl rosidl_runtime_rs::Service for Play {
    type Request = Play_Request;
    type Response = Play_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Play() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__PlayNext() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__PlayNext
#[allow(missing_docs, non_camel_case_types)]
pub struct PlayNext;

impl rosidl_runtime_rs::Service for PlayNext {
    type Request = PlayNext_Request;
    type Response = PlayNext_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__PlayNext() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Record() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Record
#[allow(missing_docs, non_camel_case_types)]
pub struct Record;

impl rosidl_runtime_rs::Service for Record {
    type Request = Record_Request;
    type Response = Record_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Record() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Resume() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Resume
#[allow(missing_docs, non_camel_case_types)]
pub struct Resume;

impl rosidl_runtime_rs::Service for Resume {
    type Request = Resume_Request;
    type Response = Resume_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Resume() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Seek() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Seek
#[allow(missing_docs, non_camel_case_types)]
pub struct Seek;

impl rosidl_runtime_rs::Service for Seek {
    type Request = Seek_Request;
    type Response = Seek_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Seek() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SetRate() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__SetRate
#[allow(missing_docs, non_camel_case_types)]
pub struct SetRate;

impl rosidl_runtime_rs::Service for SetRate {
    type Request = SetRate_Request;
    type Response = SetRate_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SetRate() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Snapshot() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Snapshot
#[allow(missing_docs, non_camel_case_types)]
pub struct Snapshot;

impl rosidl_runtime_rs::Service for Snapshot {
    type Request = Snapshot_Request;
    type Response = Snapshot_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Snapshot() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SplitBagfile() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__SplitBagfile
#[allow(missing_docs, non_camel_case_types)]
pub struct SplitBagfile;

impl rosidl_runtime_rs::Service for SplitBagfile {
    type Request = SplitBagfile_Request;
    type Response = SplitBagfile_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__SplitBagfile() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StartDiscovery() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__StartDiscovery
#[allow(missing_docs, non_camel_case_types)]
pub struct StartDiscovery;

impl rosidl_runtime_rs::Service for StartDiscovery {
    type Request = StartDiscovery_Request;
    type Response = StartDiscovery_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StartDiscovery() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Stop() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__Stop
#[allow(missing_docs, non_camel_case_types)]
pub struct Stop;

impl rosidl_runtime_rs::Service for Stop {
    type Request = Stop_Request;
    type Response = Stop_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__Stop() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StopDiscovery() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__StopDiscovery
#[allow(missing_docs, non_camel_case_types)]
pub struct StopDiscovery;

impl rosidl_runtime_rs::Service for StopDiscovery {
    type Request = StopDiscovery_Request;
    type Response = StopDiscovery_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__StopDiscovery() }
    }
}




#[link(name = "rosbag2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__TogglePaused() -> *const std::ffi::c_void;
}

// Corresponds to rosbag2_interfaces__srv__TogglePaused
#[allow(missing_docs, non_camel_case_types)]
pub struct TogglePaused;

impl rosidl_runtime_rs::Service for TogglePaused {
    type Request = TogglePaused_Request;
    type Response = TogglePaused_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__rosbag2_interfaces__srv__TogglePaused() }
    }
}


