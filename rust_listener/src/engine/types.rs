use crate::engine::cpu_engine::CPUEngine;

pub trait Engine {
    fn check(&self) -> Result<bool, anyhow::Error>;
}

pub type AppEngine<'a> = CPUEngine<'a>;