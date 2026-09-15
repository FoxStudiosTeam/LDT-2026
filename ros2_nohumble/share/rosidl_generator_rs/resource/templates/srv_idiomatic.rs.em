@{
req_res_specs = []

for subfolder, service in srv_specs:
    req_res_specs.append((subfolder, service.request_message))
    req_res_specs.append((subfolder, service.response_message))
}@

@{
TEMPLATE(
    'templates/msg_idiomatic.rs.em',
    package_name=package_name, interface_path=interface_path,
    msg_specs=req_res_specs,
    get_rs_name=get_rs_name,
    get_rs_type=get_rs_type,
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)
}@

@[for subfolder, srv_spec in srv_specs]

@{
type_name = srv_spec.namespaced_type.name
}@

#[link(name = "@(package_name)__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__@(package_name)__@(subfolder)__@(type_name)() -> *const std::ffi::c_void;
}

// Corresponds to @(package_name)__@(subfolder)__@(type_name)
#[allow(missing_docs, non_camel_case_types)]
pub struct @(type_name);

impl rosidl_runtime_rs::Service for @(type_name) {
    type Request = @(type_name)_Request;
    type Response = @(type_name)_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__@(package_name)__@(subfolder)__@(type_name)() }
    }
}

@[end for]
