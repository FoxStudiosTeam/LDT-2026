use std::env;
use ros2_client::{Context, ContextOptions};
use crate::error::Error;

pub fn create_context() -> Result<Context, Error> {
    let opt = ContextOptions::new().domain_id(
        env::var("ROS_DOMAIN_ID")
        .ok()
        .and_then(|value| value.parse::<u16>().ok())
        .unwrap_or(0)
    );
    Context::with_options(opt).map_err(|err| Error::CreateError(err, "Failed to create context"))
}