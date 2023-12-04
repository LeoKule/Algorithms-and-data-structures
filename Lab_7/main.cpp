#include <iostream>
#include <vector>

template <typename T>
void shellSort(std::vector<T>& arr) {
    int n = arr.size();

    // Выбираем начальный шаг (gap)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Применяем сортировку вставками с заданным шагом
        for (int i = gap; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    std::vector<int> targetArray{12, 0, -21, 7, 8, 4, -10, 15};

    // Применяем сортировку Шелла
    shellSort(targetArray);

    // Вывод отсортированного массива
    for (const auto& element : targetArray) {
        std::cout << element << " ";
    }

    return 0;
}
