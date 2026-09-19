use ros2_client::{Context, ContextOptions};
use shared::error::{AppError, ErrCtx};

pub fn create_context(domain_id: u16) -> Result<Context, AppError> {
    let opt = ContextOptions::new().domain_id(domain_id);
    Context::with_options(opt).app_error()
}
