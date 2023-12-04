#include <iostream>
#include <vector>

// Функция для нахождения максимального значения в векторе
template <typename T>
T getMax(const std::vector<T>& arr) {
    T max = arr[0];
    for (const auto& element : arr) {
        if (element > max) {
            max = element;
        }
    }
    return max;
}

// Функция для выполнения сортировки методом поразрядов
template <typename T>
void radixSort(std::vector<T>& arr) {
    T max = getMax(arr); // Находим максимальное число

    // Проводим сортировку по каждому разряду, начиная с младшего
    for (T exp = 1; max / exp > 0; exp *= 10) {
        // Выполняем сортировку подсчетом для текущего разряда
        std::vector<T> output(arr.size());
        std::vector<T> count(10, 0);

        for (size_t i = 0; i < arr.size(); ++i) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = output[i];
        }
    }
}

int main() {
    std::vector<int> targetArray{170, 45, 75, 90, 802, 24, 2, 66};

    // Применяем сортировку методом поразрядов
    radixSort(targetArray);

    // Вывод отсортированного массива
    for (const auto& element : targetArray) {
        std::cout << element << " ";
    }

    return 0;
}
