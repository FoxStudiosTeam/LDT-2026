#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to type_description_interfaces__msg__Field
/// Represents a single field in a type.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Field {
    /// Name of the field.
    pub name: std::string::String,

    /// Type of the field, including details about the type like length, nested name, etc.
    pub type_: super::msg::FieldType,

    /// Literal default value of the field as a string, as it appeared in the original
    /// message description file, whether that be .msg/.srv/.action or .idl.
    pub default_value: std::string::String,

}



impl Default for Field {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Field::default())
  }
}

impl rosidl_runtime_rs::Message for Field {
  type RmwMsg = super::msg::rmw::Field;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        type_: super::msg::FieldType::into_rmw_message(std::borrow::Cow::Owned(msg.type_)).into_owned(),
        default_value: msg.default_value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        type_: super::msg::FieldType::into_rmw_message(std::borrow::Cow::Borrowed(&msg.type_)).into_owned(),
        default_value: msg.default_value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      type_: super::msg::FieldType::from_rmw_message(msg.type_),
      default_value: msg.default_value.to_string(),
    }
  }
}


// Corresponds to type_description_interfaces__msg__FieldType
/// Represents the type of a field and related meta-data.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FieldType {
    /// Identifying number for the type of the field, using one of the above constants.
    pub type_id: u8,

    /// Only used when the type is an array or a bounded sequence.
    /// In the case of an array, this is the fixed capacity of the array.
    /// In the case of a bounded sequence, this is the maximum capacity of the sequence.
    /// In all other cases this field is unused.
    pub capacity: u64,

    /// Only used when the type is a fixed or bounded string/wstring, or a array/sequence of those.
    /// In the case of a fixed string/wstring, it is the fixed length of the string.
    /// In the case of a bounded string/wstring, it is the maximum capacity of the string.
    /// In the case of an array/sequence of fixed string/wstring, it is the fixed length of the strings.
    /// In the case of an array/sequence of bounded string/wstring, it is the maximum capacity of the strings.
    /// It is not currently possible to have different string capacities per element in the array/sequence.
    pub string_capacity: u64,

    /// Only used when the type is a nested type or array/sequence of nested types.
    /// This is limited to 255 characters.
    /// TODO(wjwwood): this 255 character limit was chosen due to this being the limit
    ///   for DDSI-RTPS based middlewares, which is the most commonly used right now.
    ///   We lack a ROS 2 specific limit in our design documents, but we should update
    ///   this and/or link to the design doc when that is available.
    pub nested_type_name: rosidl_runtime_rs::BoundedString<255>,

}

impl FieldType {
    /// A constant for each type supported according to:
    ///   http://design.ros2.org/articles/legacy_interface_definition.html
    /// and:
    ///   http://design.ros2.org/articles/idl_interface_definition.html
    /// Order is loosely coupled to the order of appearance in the IDL 4.2 spec:
    ///  https://www.omg.org/spec/IDL/4.2
    /// Layout of constants across the 0-255 decimal values in the uint8:
    ///
    /// - 000    : Reserved for "not set"
    /// - 001-048: Primitive types, strings, and reserved space for future primitive types
    /// - 049-096: Fixed sized array of primitive and string types
    /// - 097-144: Bounded Sequences of primitive and string types
    /// - 145-192: Unbounded Sequences of primitive and string types
    /// - 193-255: Reserved space for future array/sequence-like types
    pub const FIELD_TYPE_NOT_SET: u8 = 0;

    /// Nested type defined in other .msg/.idl files.
    pub const FIELD_TYPE_NESTED_TYPE: u8 = 1;

    /// Integer Types
    pub const FIELD_TYPE_INT8: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64: u8 = 9;

    /// Floating-Point Types
    pub const FIELD_TYPE_FLOAT: u8 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE: u8 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE: u8 = 12;

    /// Char and WChar Types
    pub const FIELD_TYPE_CHAR: u8 = 13;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR: u8 = 14;

    /// Boolean Type
    pub const FIELD_TYPE_BOOLEAN: u8 = 15;

    /// Byte/Octet Type
    pub const FIELD_TYPE_BYTE: u8 = 16;

    /// String Types
    pub const FIELD_TYPE_STRING: u8 = 17;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING: u8 = 18;

    /// Fixed String Types
    pub const FIELD_TYPE_FIXED_STRING: u8 = 19;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING: u8 = 20;

    /// Bounded String Types
    pub const FIELD_TYPE_BOUNDED_STRING: u8 = 21;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING: u8 = 22;

    /// Fixed Sized Array Types
    pub const FIELD_TYPE_NESTED_TYPE_ARRAY: u8 = 49;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_ARRAY: u8 = 50;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_ARRAY: u8 = 51;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_ARRAY: u8 = 52;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_ARRAY: u8 = 53;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_ARRAY: u8 = 54;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_ARRAY: u8 = 55;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_ARRAY: u8 = 56;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_ARRAY: u8 = 57;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_ARRAY: u8 = 58;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_ARRAY: u8 = 59;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_ARRAY: u8 = 60;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_ARRAY: u8 = 61;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_ARRAY: u8 = 62;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_ARRAY: u8 = 63;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_ARRAY: u8 = 64;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_ARRAY: u8 = 65;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_ARRAY: u8 = 66;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_ARRAY: u8 = 67;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_ARRAY: u8 = 68;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_ARRAY: u8 = 69;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_ARRAY: u8 = 70;

    /// Bounded Sequence Types
    pub const FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE: u8 = 97;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_BOUNDED_SEQUENCE: u8 = 98;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_BOUNDED_SEQUENCE: u8 = 99;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_BOUNDED_SEQUENCE: u8 = 100;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_BOUNDED_SEQUENCE: u8 = 101;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_BOUNDED_SEQUENCE: u8 = 102;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_BOUNDED_SEQUENCE: u8 = 103;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_BOUNDED_SEQUENCE: u8 = 104;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_BOUNDED_SEQUENCE: u8 = 105;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_BOUNDED_SEQUENCE: u8 = 106;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_BOUNDED_SEQUENCE: u8 = 107;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_BOUNDED_SEQUENCE: u8 = 108;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_BOUNDED_SEQUENCE: u8 = 109;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_BOUNDED_SEQUENCE: u8 = 110;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_BOUNDED_SEQUENCE: u8 = 111;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_BOUNDED_SEQUENCE: u8 = 112;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_BOUNDED_SEQUENCE: u8 = 113;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_BOUNDED_SEQUENCE: u8 = 114;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_BOUNDED_SEQUENCE: u8 = 115;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_BOUNDED_SEQUENCE: u8 = 116;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_BOUNDED_SEQUENCE: u8 = 117;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_BOUNDED_SEQUENCE: u8 = 118;

    /// Unbounded Sequence Types
    pub const FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE: u8 = 145;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE: u8 = 146;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT8_UNBOUNDED_SEQUENCE: u8 = 147;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT16_UNBOUNDED_SEQUENCE: u8 = 148;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT16_UNBOUNDED_SEQUENCE: u8 = 149;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE: u8 = 150;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE: u8 = 151;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_INT64_UNBOUNDED_SEQUENCE: u8 = 152;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_UINT64_UNBOUNDED_SEQUENCE: u8 = 153;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE: u8 = 154;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE: u8 = 155;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_LONG_DOUBLE_UNBOUNDED_SEQUENCE: u8 = 156;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_CHAR_UNBOUNDED_SEQUENCE: u8 = 157;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WCHAR_UNBOUNDED_SEQUENCE: u8 = 158;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOOLEAN_UNBOUNDED_SEQUENCE: u8 = 159;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BYTE_UNBOUNDED_SEQUENCE: u8 = 160;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE: u8 = 161;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_WSTRING_UNBOUNDED_SEQUENCE: u8 = 162;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_STRING_UNBOUNDED_SEQUENCE: u8 = 163;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_FIXED_WSTRING_UNBOUNDED_SEQUENCE: u8 = 164;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_STRING_UNBOUNDED_SEQUENCE: u8 = 165;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIELD_TYPE_BOUNDED_WSTRING_UNBOUNDED_SEQUENCE: u8 = 166;

}


impl Default for FieldType {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FieldType::default())
  }
}

impl rosidl_runtime_rs::Message for FieldType {
  type RmwMsg = super::msg::rmw::FieldType;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_id: msg.type_id,
        capacity: msg.capacity,
        string_capacity: msg.string_capacity,
        nested_type_name: msg.nested_type_name,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_id: msg.type_id,
      capacity: msg.capacity,
      string_capacity: msg.string_capacity,
        nested_type_name: msg.nested_type_name.clone(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_id: msg.type_id,
      capacity: msg.capacity,
      string_capacity: msg.string_capacity,
      nested_type_name: msg.nested_type_name,
    }
  }
}


// Corresponds to type_description_interfaces__msg__IndividualTypeDescription
/// Represents a single type, without the types it references, if any.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IndividualTypeDescription {
    /// Name of the type.
    /// This is limited to 255 characters.
    /// TODO(wjwwood): this 255 character limit was chosen due to this being the limit
    ///   for DDSI-RTPS based middlewares, which is the most commonly used right now.
    ///   We lack a ROS 2 specific limit in our design documents, but we should update
    ///   this and/or link to the design doc when that is available.
    pub type_name: rosidl_runtime_rs::BoundedString<255>,

    /// Fields of the type.
    pub fields: Vec<super::msg::Field>,

}



impl Default for IndividualTypeDescription {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::IndividualTypeDescription::default())
  }
}

impl rosidl_runtime_rs::Message for IndividualTypeDescription {
  type RmwMsg = super::msg::rmw::IndividualTypeDescription;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name,
        fields: msg.fields
          .into_iter()
          .map(|elem| super::msg::Field::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name.clone(),
        fields: msg.fields
          .iter()
          .map(|elem| super::msg::Field::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_name: msg.type_name,
      fields: msg.fields
          .into_iter()
          .map(super::msg::Field::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to type_description_interfaces__msg__KeyValue
/// Represents an arbitrary key-value pair for application-specific information.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct KeyValue {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: std::string::String,

}



impl Default for KeyValue {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::KeyValue::default())
  }
}

impl rosidl_runtime_rs::Message for KeyValue {
  type RmwMsg = super::msg::rmw::KeyValue;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key.to_string(),
      value: msg.value.to_string(),
    }
  }
}


// Corresponds to type_description_interfaces__msg__TypeDescription
/// Represents a complete type description, including the type itself as well as the types it references.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeDescription {
    /// Description of the type.
    pub type_description: super::msg::IndividualTypeDescription,

    /// Descriptions of all referenced types, recursively.
    pub referenced_type_descriptions: Vec<super::msg::IndividualTypeDescription>,

}



impl Default for TypeDescription {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TypeDescription::default())
  }
}

impl rosidl_runtime_rs::Message for TypeDescription {
  type RmwMsg = super::msg::rmw::TypeDescription;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_description: super::msg::IndividualTypeDescription::into_rmw_message(std::borrow::Cow::Owned(msg.type_description)).into_owned(),
        referenced_type_descriptions: msg.referenced_type_descriptions
          .into_iter()
          .map(|elem| super::msg::IndividualTypeDescription::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_description: super::msg::IndividualTypeDescription::into_rmw_message(std::borrow::Cow::Borrowed(&msg.type_description)).into_owned(),
        referenced_type_descriptions: msg.referenced_type_descriptions
          .iter()
          .map(|elem| super::msg::IndividualTypeDescription::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_description: super::msg::IndividualTypeDescription::from_rmw_message(msg.type_description),
      referenced_type_descriptions: msg.referenced_type_descriptions
          .into_iter()
          .map(super::msg::IndividualTypeDescription::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to type_description_interfaces__msg__TypeSource
/// Represents the original source of a ROS 2 interface definition.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeSource {
    /// ROS interface type name, in PACKAGE/NAMESPACE/TYPENAME format.
    pub type_name: std::string::String,

    /// The type of the original source file, typically matching the file extension.
    /// Well-known encodings: "idl", "msg", "srv", "action", "dynamic", "implicit".
    /// "dynamic" specifies a type created programmatically by a user, thus having no source.
    /// "implicit" specifies a type created automatically as a subtype of a
    /// complex type (service or action) - such as the request message for a service.
    /// Implicit types will have no contents, the full source will be available on the parent srv/action.
    pub encoding: std::string::String,

    /// Dumped contents of the interface definition source file.
    /// If `encoding` is "dynamic" or "implicit", this field will be empty.
    pub raw_file_contents: std::string::String,

}



impl Default for TypeSource {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TypeSource::default())
  }
}

impl rosidl_runtime_rs::Message for TypeSource {
  type RmwMsg = super::msg::rmw::TypeSource;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name.as_str().into(),
        encoding: msg.encoding.as_str().into(),
        raw_file_contents: msg.raw_file_contents.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_name: msg.type_name.as_str().into(),
        encoding: msg.encoding.as_str().into(),
        raw_file_contents: msg.raw_file_contents.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_name: msg.type_name.to_string(),
      encoding: msg.encoding.to_string(),
      raw_file_contents: msg.raw_file_contents.to_string(),
    }
  }
}


