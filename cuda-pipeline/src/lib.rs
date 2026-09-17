// 1. Объявляем интерфейс к Си-библиотеке (CUDA)
unsafe extern "C" {
    unsafe fn run_vector_add(a: *const f32, b: *const f32, c: *mut f32, n: i32);
}

// 2. Делаем безопасную обертку для Rust
pub fn vector_add(a: &[f32], b: &[f32]) -> Vec<f32> {
    assert_eq!(a.len(), b.len(), "Массивы должны быть одинаковой длины!");
    
    let n = a.len();
    let mut c = vec![0.0f32; n];

    // Вызываем unsafe код один раз внутри контролируемой обертки
    unsafe {
        run_vector_add(
            a.as_ptr(),
            b.as_ptr(),
            c.as_mut_ptr(),
            n as i32,
        );
    }

    c
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
