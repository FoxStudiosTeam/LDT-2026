#ifndef KERNEL_CUH
#define KERNEL_CUH

#ifdef __cplusplus
extern "C" {
#endif

void run_vector_add(const float* a, const float* b, float* c, int n);

float* pin_gpu_addr(size_t size);

cudaError_t normalize_tunnel(float* host_x, float* host_y, float* host_z);

#ifdef __cplusplus
}
#endif

#endif
