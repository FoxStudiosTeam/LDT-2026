use std::error::Error;
use ros2_client::{Context, Node};

mod context;
pub mod node;
pub struct Ros {
    context: Context,
    node: Node,
}

impl Ros {
    pub fn new() -> Result<Self, Box<dyn Error>> {
        let context = context::create_context().expect("Failed to create context");
        let mut node = node::create_node(&context)?;
        
        node::start_spinner(&mut node);
        
        Ok(Self { context, node })
    }

    pub fn context(&self) -> &Context {
        &self.context
    }
    pub fn node(&self) -> &Node {
        &self.node
    }

    pub fn mutable_node(&mut self) -> &mut Node {
        &mut self.node
    }

    pub fn domain_participant(&self) -> ros2_client::rustdds::dds::DomainParticipant {
        self.context.domain_participant()
    }
}