#include "kernel.cuh"
#include <cuda_runtime.h>
#include <math.h>

#define BLOCK_SZ 256

// Структура нашего реестра
struct PointerPair {
    float* host_ptr;
    float* device_ptr;
    size_t size;
};

// Хранилище на 12 буферов
static PointerPair g_registry[12] = { {NULL, NULL, 0} };

// Статические буферы (выделено под 256 блоков)
static float* g_dev_block_totals = NULL;   // Локальные медианы X
static float* g_dev_block_offsets = NULL;  // Локальные медианы Y
static float* g_host_block_totals = NULL;
static float* g_host_block_offsets = NULL;

// Переменные для поиска минимума/максимума Z
static float* d_z_min_max = NULL;

extern "C" float* pin_gpu_addr(size_t size) {
    if (g_dev_block_totals == NULL) {
        cudaMalloc(&g_dev_block_totals, 256 * sizeof(float));
        cudaMalloc(&g_dev_block_offsets, 256 * sizeof(float));
        cudaMalloc(&d_z_min_max, 2 * sizeof(float)); 
        cudaHostAlloc((void**)&g_host_block_totals, 256 * sizeof(float), cudaHostAllocDefault);
        cudaHostAlloc((void**)&g_host_block_offsets, 256 * sizeof(float), cudaHostAllocDefault);
    }

    float* host_ptr = NULL;
    size_t bytes = size * sizeof(float);

    cudaError_t err = cudaHostAlloc((void**) &host_ptr, bytes, cudaHostAllocMapped);
    if (err != cudaSuccess) return NULL;

    float* device_ptr = NULL;
    err = cudaHostGetDevicePointer(&device_ptr, host_ptr, 0);
    if (err != cudaSuccess) {
        cudaFreeHost(host_ptr);
        return NULL;
    }

    bool saved = false;
    for (int i = 0; i < 12; i++) {
        if (g_registry[i].host_ptr == NULL) {
            g_registry[i].host_ptr = host_ptr;
            g_registry[i].device_ptr = device_ptr;
            g_registry[i].size = size;
            saved = true;
            break;
        }
    }

    if (!saved) {
        cudaFreeHost(host_ptr);
        return NULL;
    }

    return host_ptr;
}

static float* get_device_ptr(float* host_ptr) {
    for (int i = 0; i < 12; i++) {
        if (g_registry[i].host_ptr == host_ptr) {
            return g_registry[i].device_ptr;
        }
    }
    return NULL;
}

// 1. Быстрый поиск диапазона глубин Z (min/max)
__global__ void find_z_range(const float* z, size_t size, float* d_res) {
    __shared__ float s_min[BLOCK_SZ];
    __shared__ float s_max[BLOCK_SZ];
    
    int tid = threadIdx.x;
    float local_min = 1e9f;
    float local_max = -1e9f;
    
    for (size_t i = blockIdx.x * blockDim.x + tid; i < size; i += blockDim.x * gridDim.x) {
        float val = z[i];
        if (val < local_min) local_min = val;
        if (val > local_max) local_max = val;
    }
    
    s_min[tid] = local_min;
    s_max[tid] = local_max;
    __syncthreads();
    
    for (int stride = blockDim.x / 2; stride > 0; stride /= 2) {
        if (tid < stride) {
            if (s_min[tid + stride] < s_min[tid]) s_min[tid] = s_min[tid + stride];
            if (s_max[tid + stride] > s_max[tid]) s_max[tid] = s_max[tid + stride];
        }
        __syncthreads();
    }
    
    if (tid == 0) {
        atomicMin((int*)&d_res[0], __float_as_int(s_min[0]));
        atomicMax((int*)&d_res[1], __float_as_int(s_max[0]));
    }
}

// 2. Расчет локальных медиан для конкретного Z-сегмента
__global__ void calc_local_mediana(const float* coord, const float* z, size_t size, 
                                   float z_min, float z_step, int target_slice, float* res) {
    float low = -1e9f; 
    float high = 1e9f;
    float median = 0.0f;
    
    size_t local_size = 0;
    for (size_t i = blockIdx.x * blockDim.x + threadIdx.x; i < size; i += blockDim.x * gridDim.x) {
        int slice = (int)((z[i] - z_min) / z_step);
        if (slice == target_slice) {
            local_size++;
        }
    }
    
    __shared__ size_t total_points;
    if (threadIdx.x == 0) total_points = 0;
    __syncthreads();
    if (local_size > 0) atomicAdd((unsigned long long*)&total_points, (unsigned long long)local_size);
    __syncthreads();
    
    size_t half_size = total_points >> 1;
    if (total_points == 0) {
        if (blockIdx.x == 0 && threadIdx.x == 0) *res = 0.0f;
        return;
    }

    // 24 итерации бинарного поиска значения
    for (int iter = 0; iter < 24; ++iter) { 
        median = low + (high - low) * 0.5f;
        size_t thread_count = 0;
        
        for (size_t i = blockIdx.x * blockDim.x + threadIdx.x; i < size; i += blockDim.x * gridDim.x) {
            int slice = (int)((z[i] - z_min) / z_step);
            if (slice == target_slice && coord[i] < median) {
                thread_count++;
            }
        }
        
        __shared__ size_t total_less;
        if (threadIdx.x == 0) total_less = 0;
        __syncthreads();
        
        if (thread_count > 0) atomicAdd((unsigned long long*)&total_less, (unsigned long long)thread_count);
        __syncthreads();
        
        if (total_less < half_size) {
            low = median; 
        } else {
            high = median;
        }
        __syncthreads();
    }

    if (blockIdx.x == 0 && threadIdx.x == 0) {
        *res = median;
    }
}

// 3. Выпрямление лидарного облака по срезам
__global__ void straighten_tunnel_kernel(float* x, float* y, const float* z, size_t size, 
                                         float z_min, float z_step, 
                                         const float* medians_x, const float* medians_y) {
    size_t idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= size) return;
    
    int slice = (int)((z[idx] - z_min) / z_step);
    if (slice >= 0 && slice < 256) {
        x[idx] -= medians_x[slice];
        y[idx] -= medians_y[slice];
    }
}

extern "C" cudaError_t normalize_tunnel(float* host_x, float* host_y, float* host_z) {
    // ВЫПОЛНЕНО: Видеокарта забирает адреса памяти строго из указанных индексов реестра
    float* dev_x = g_registry[2].device_ptr;
    float* dev_y = g_registry[5].device_ptr; 
    float* dev_z = g_registry[8].device_ptr; 

    if (dev_x == NULL || dev_y == NULL || dev_z == NULL) {
        return cudaErrorInitializationError;
    }

    // Количество точек берем строго из 3-го буфера (индекс 2, соответствующий оси X)
    size_t size = g_registry[2].size;
    if (size == 0) return cudaSuccess;

    int blockSize = BLOCK_SZ;
    int gridSize = (size + blockSize - 1) / blockSize;
    if (gridSize > 256) gridSize = 256; 

    // Шаг 1: Поиск диапазона глубин по Z
    float h_z_range[2] = {1e9f, -1e9f};
    cudaMemcpy(d_z_min_max, h_z_range, 2 * sizeof(float), cudaMemcpyHostToDevice);
    
    find_z_range<<<gridSize, blockSize>>>(dev_z, size, d_z_min_max);
    cudaMemcpy(h_z_range, d_z_min_max, 2 * sizeof(float), cudaMemcpyDeviceToHost);
    
    float z_min = h_z_range[0];
    float z_max = h_z_range[1];
    float z_step = (z_max - z_min) / 256.0f;
    if (z_step < 1e-4f) z_step = 1e-4f;

    // Шаг 2: Расчет медиан X и Y для каждого из 256 сегментов
    for (int s = 0; s < 256; s++) {
        calc_local_mediana<<<gridSize, blockSize>>>(dev_x, dev_z, size, z_min, z_step, s, &g_dev_block_totals[s]);
        calc_local_mediana<<<gridSize, blockSize>>>(dev_y, dev_z, size, z_min, z_step, s, &g_dev_block_offsets[s]);
    }
    cudaDeviceSynchronize();

    // Шаг 3: Сдвигаем точки лидара в один проход
    int fullGridSize = (size + blockSize - 1) / blockSize;
    straighten_tunnel_kernel<<<fullGridSize, blockSize>>>(dev_x, dev_y, dev_z, size, z_min, z_step, g_dev_block_totals, g_dev_block_offsets);
    cudaDeviceSynchronize();

    return cudaSuccess;
}

// Заглушки для совместимости
__global__ void add_block_offsets(float* z, const float* offsets, size_t size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= size) return;
    z[idx] += offsets[blockIdx.x];
}

__global__ void vector_add_kernel(const float* a, const float* b, float* c, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n) c[idx] = a[idx] + b[idx];
}

extern "C" void run_vector_add(const float* a, const float* b, float* c, int n) {
    float *d_a, *d_b, *d_c; size_t bytes = n * sizeof(float);
    cudaMalloc(&d_a, bytes); cudaMalloc(&d_b, bytes); cudaMalloc(&d_c, bytes);
    cudaMemcpy(d_a, a, bytes, cudaMemcpyHostToDevice); cudaMemcpy(d_b, b, bytes, cudaMemcpyHostToDevice);
    int blockSize = 256; int gridSize = (n + blockSize - 1) / blockSize;
    vector_add_kernel<<<gridSize, blockSize>>>(d_a, d_b, d_c, n);
    cudaMemcpy(c, d_c, bytes, cudaMemcpyDeviceToHost);
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
}
