#![allow(non_camel_case_types)]
#![allow(clippy::derive_partial_eq_without_eq)]
#![allow(clippy::upper_case_acronyms)]

@[for namespace in generated_namespaces]@
#[path = "@(namespace).rs"]
mod @(namespace)_idiomatic;
pub mod @(namespace) {
    pub use super::@(namespace)_idiomatic::*;
    pub mod rmw;
}

@[end for]@
