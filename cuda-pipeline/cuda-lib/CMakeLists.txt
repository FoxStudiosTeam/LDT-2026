cmake_minimum_required(VERSION 3.18)
project(CudaLib LANGUAGES CXX CUDA)

set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# ВОТ ЗДЕСЬ УКАЗЫВАЕМ СТРОГО НАШИ КАРТЫ И УБИРАЕМ NATIVE
set(CMAKE_CUDA_ARCHITECTURES "86;89")

# Собираем СТАТИЧЕСКУЮ библиотеку (вместо add_executable)
add_library(cuda_vector_add STATIC
    src/kernel.cu
)

target_include_directories(cuda_vector_add PUBLIC include)

# Для Windows: принудительно линкуем рантайм CUDA, чтобы Rust его не потерял
target_link_libraries(cuda_vector_add PUBLIC cudart_static)
