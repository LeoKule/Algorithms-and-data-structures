#include <iostream>
#include <vector>

class MergeSort {
public:
    // Функция сортировки слиянием
    static void sort(std::vector<int>& array) {
        if (array.size() > 1) {
            int mid = array.size() / 2;

            // Разделяем массив на две половины
            std::vector<int> left(array.begin(), array.begin() + mid);
            std::vector<int> right(array.begin() + mid, array.end());

            // Рекурсивно сортируем каждую половину
            sort(left);
            sort(right);

            // Объединяем отсортированные половины
            merge(array, left, right);
        }
    }

private:
    // Функция для объединения двух отсортированных массивов
    static void merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;

        // Сравниваем элементы из левого и правого массивов и объединяем их в результирующий массив
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        // Добавляем оставшиеся элементы из левого массива (если они есть)
        while (i < left.size()) {
            array[k++] = left[i++];
        }

        // Добавляем оставшиеся элементы из правого массива (если они есть)
        while (j < right.size()) {
            array[k++] = right[j++];
        }
    }
};

int main() {
    // Пример использования сортировки слиянием
    setlocale(LC_ALL, "Russian");

    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    std::cout << "Исходный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Вызываем метод сортировки слиянием
    MergeSort::sort(array);

    std::cout << "Отсортированный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
