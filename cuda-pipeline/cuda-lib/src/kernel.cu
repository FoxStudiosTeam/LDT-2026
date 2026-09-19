#include "kernel.cuh"

// CUDA-ядро, выполняемое на GPU
__global__ void vector_add_kernel(const float* a, const float* b, float* c, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n) {
        c[idx] = a[idx] + b[idx];
    }
}

// Функция-обертка для запуска из C++ кода
extern "C" void run_vector_add(const float* a, const float* b, float* c, int n) {
    float *d_a, *d_b, *d_c;
    size_t bytes = n * sizeof(float);

    // Выделение памяти на GPU
    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_c, bytes);

    // Копирование данных на GPU
    cudaMemcpy(d_a, a, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, bytes, cudaMemcpyHostToDevice);

    // Конфигурация запуска (например, блоки по 256 потоков)
    int blockSize = 256;
    int gridSize = (n + blockSize - 1) / blockSize;

    // Запуск ядра
    vector_add_kernel<<<gridSize, blockSize>>>(d_a, d_b, d_c, n);

    // Ожидание завершения и копирование результата обратно
    cudaMemcpy(c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Освобождение памяти
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}

extern "C" float* pin_gpu_addr(size_t size) {
    float* host_ptr = NULL;
    size_t bytes = size * sizeof(float);

    cudaError err = cudaHostAlloc((void**) &host_ptr, bytes, cudaHostAllocMapped);
    if (err != cudaSuccess) {
        return NULL;
    }
    return host_ptr;
}