#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to rosbag2_interfaces__msg__ReadSplitEvent
/// The full path of the file that was finished and closed

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ReadSplitEvent {

    // This member is not documented.
    #[allow(missing_docs)]
    pub closed_file: std::string::String,

    /// The full path of the new file that was opened to continue playback
    pub opened_file: std::string::String,

    /// The fully qualified node name of the event sender
    pub node_name: std::string::String,

}



impl Default for ReadSplitEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ReadSplitEvent::default())
  }
}

impl rosidl_runtime_rs::Message for ReadSplitEvent {
  type RmwMsg = super::msg::rmw::ReadSplitEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        closed_file: msg.closed_file.as_str().into(),
        opened_file: msg.opened_file.as_str().into(),
        node_name: msg.node_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        closed_file: msg.closed_file.as_str().into(),
        opened_file: msg.opened_file.as_str().into(),
        node_name: msg.node_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      closed_file: msg.closed_file.to_string(),
      opened_file: msg.opened_file.to_string(),
      node_name: msg.node_name.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__msg__WriteSplitEvent
/// The full path of the file that was finished and closed

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WriteSplitEvent {

    // This member is not documented.
    #[allow(missing_docs)]
    pub closed_file: std::string::String,

    /// The full path of the new file that was created to continue recording
    pub opened_file: std::string::String,

    /// The fully qualified node name of the event sender
    pub node_name: std::string::String,

}



impl Default for WriteSplitEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::WriteSplitEvent::default())
  }
}

impl rosidl_runtime_rs::Message for WriteSplitEvent {
  type RmwMsg = super::msg::rmw::WriteSplitEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        closed_file: msg.closed_file.as_str().into(),
        opened_file: msg.opened_file.as_str().into(),
        node_name: msg.node_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        closed_file: msg.closed_file.as_str().into(),
        opened_file: msg.opened_file.as_str().into(),
        node_name: msg.node_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      closed_file: msg.closed_file.to_string(),
      opened_file: msg.opened_file.to_string(),
      node_name: msg.node_name.to_string(),
    }
  }
}


// Corresponds to rosbag2_interfaces__msg__MessagesLostEventTopicStat
/// The name of the topic on which the messages were lost

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MessagesLostEventTopicStat {

    // This member is not documented.
    #[allow(missing_docs)]
    pub topic_name: std::string::String,

    /// The number of messages lost since the last event on a DDS transport layer
    pub messages_lost_in_transport: u64,

    /// The number of messages lost since the last event in the Rosbag2 recorder
    pub messages_lost_in_recorder: u64,

}



impl Default for MessagesLostEventTopicStat {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MessagesLostEventTopicStat::default())
  }
}

impl rosidl_runtime_rs::Message for MessagesLostEventTopicStat {
  type RmwMsg = super::msg::rmw::MessagesLostEventTopicStat;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        topic_name: msg.topic_name.as_str().into(),
        messages_lost_in_transport: msg.messages_lost_in_transport,
        messages_lost_in_recorder: msg.messages_lost_in_recorder,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        topic_name: msg.topic_name.as_str().into(),
      messages_lost_in_transport: msg.messages_lost_in_transport,
      messages_lost_in_recorder: msg.messages_lost_in_recorder,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      topic_name: msg.topic_name.to_string(),
      messages_lost_in_transport: msg.messages_lost_in_transport,
      messages_lost_in_recorder: msg.messages_lost_in_recorder,
    }
  }
}


// Corresponds to rosbag2_interfaces__msg__MessagesLostEvent
/// The fully qualified node name of the event sender

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MessagesLostEvent {

    // This member is not documented.
    #[allow(missing_docs)]
    pub node_name: std::string::String,

    /// Per topic statistics about messages lost since the last event. Topics with no lost messages
    /// will not be included
    pub messages_lost_statistics: Vec<super::msg::MessagesLostEventTopicStat>,

}



impl Default for MessagesLostEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MessagesLostEvent::default())
  }
}

impl rosidl_runtime_rs::Message for MessagesLostEvent {
  type RmwMsg = super::msg::rmw::MessagesLostEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_name: msg.node_name.as_str().into(),
        messages_lost_statistics: msg.messages_lost_statistics
          .into_iter()
          .map(|elem| super::msg::MessagesLostEventTopicStat::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_name: msg.node_name.as_str().into(),
        messages_lost_statistics: msg.messages_lost_statistics
          .iter()
          .map(|elem| super::msg::MessagesLostEventTopicStat::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      node_name: msg.node_name.to_string(),
      messages_lost_statistics: msg.messages_lost_statistics
          .into_iter()
          .map(super::msg::MessagesLostEventTopicStat::from_rmw_message)
          .collect(),
    }
  }
}


