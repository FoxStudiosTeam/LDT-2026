fn main() {
    let dst = cmake::Config::new("cuda-lib")
        .no_build_target(true) // <- ЗАПРЕЩАЕТ искать install.vcxproj
        // === ЯВНО ЗАДАЕМ АРХИТЕКТУРЫ, ЧТОБЫ УБРАТЬ NATIVE ===
        .define("CMAKE_CUDA_ARCHITECTURES", "86;89") 
        .build();

    // CMake при no_build_target положит либу в директорию сборки.
    // Нам нужно немного скорректировать пути поиска:
    println!("cargo:rustc-link-search=native={}/build", dst.display());
    println!("cargo:rustc-link-search=native={}/build/Debug", dst.display());
    println!("cargo:rustc-link-search=native={}/build/Release", dst.display());

    println!("cargo:rustc-link-lib=static=cuda_vector_add");
    if let Ok(cuda_path) = std::env::var("CUDA_PATH") {
        println!("cargo:rustc-link-search=native={}/lib/x64", cuda_path);
    } else {
        println!("cargo:rustc-link-search=native=/usr/local/cuda/lib64");
    }
    println!("cargo:rustc-link-lib=dylib=cudart");
}
