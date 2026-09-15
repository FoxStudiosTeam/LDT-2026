#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

@{
TEMPLATE(
    '../templates/srv_rmw.rs.em',
    package_name=package_name, interface_path=interface_path,
    srv_specs=srv_specs,
    get_rs_name=get_rs_name,
    get_rs_type=make_get_rs_type(False),
    pre_field_serde=pre_field_serde,
    constant_value_to_rs=constant_value_to_rs)
}@
