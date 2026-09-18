use crate::engine::cpu_engine::CPUEngine;

pub trait Engine<const SIZE : usize> {
    fn check(&self) -> Result<bool, anyhow::Error>;
}

pub type AppEngine<'a, const SIZE : usize> = CPUEngine<'a,SIZE>;