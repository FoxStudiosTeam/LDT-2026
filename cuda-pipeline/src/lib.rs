// 1. Объявляем интерфейс к Си-библиотеке (CUDA)
unsafe extern "C" {
    unsafe fn run_vector_add(a: *const f32, b: *const f32, c: *mut f32, n: i32);
    unsafe fn pin_gpu_addr(size : usize) -> *mut f32;
    unsafe fn normalize_tunnel(x: *const f32, y: *const f32, z: *const f32) -> i32;
}

// 2. Делаем безопасную обертку для Rust
pub fn vector_add(a: &[f32], b: &[f32]) -> Vec<f32> {
    assert_eq!(a.len(), b.len(), "Массивы должны быть одинаковой длины!");

    let n = a.len();
    let mut c = vec![0.0f32; n];

    // Вызываем unsafe код один раз внутри контролируемой обертки
    unsafe {
        run_vector_add(a.as_ptr(), b.as_ptr(), c.as_mut_ptr(), n as i32);
    }

    c
}

pub fn pin_gpu(size : usize) -> [*mut f32;3] {
    unsafe {
        let pinned_addr_frame_0 = pin_gpu_addr(size);
        let pinned_addr_frame_1 = pin_gpu_addr(size);
        let pinned_addr_frame_2 = pin_gpu_addr(size);

        if pinned_addr_frame_0.is_null() || pinned_addr_frame_1.is_null() || pinned_addr_frame_2.is_null() {
            panic!("Ошибка выделения памяти (смотри в IOMMU)");
        }

        [pinned_addr_frame_0, pinned_addr_frame_1, pinned_addr_frame_2]
    }
}

pub fn normalize_tunnel_wrapped(x: *const f32, y: *const f32, z: *const f32) -> i32 {
    unsafe {
        normalize_tunnel(x,y,z)
    }
}

// 3. Блок тестов для проверки работоспособности
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_cuda_vector_add() {
        let n = 1000;
        let h_a = vec![1.5f32; n];
        let h_b = vec![2.5f32; n];

        // Вызываем нашу функцию, которая внутри дергает CUDA
        let h_c = vector_add(&h_a, &h_b);

        // Проверяем, что каждый элемент равен 4.0 (1.5 + 2.5)
        for val in h_c {
            assert_eq!(val, 4.0f32);
        }

        println!("Тест пройден! CUDA вернула правильные данные.");
    }
}
