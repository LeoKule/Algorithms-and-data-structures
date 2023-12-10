#include <iostream>
#include <vector>

class QuickSort {
public:
    // Функция быстрой сортировки
    static void sort(std::vector<int>& array) {
        quickSort(array, 0, array.size() - 1);
    }

private:
    // Вспомогательная функция быстрой сортировки
    static void quickSort(std::vector<int>& array, int low, int high) {
        if (low < high) {
            // Разделяем массив и получаем индекс опорного элемента
            int pivotIndex = partition(array, low, high);

            // Рекурсивно сортируем две половины массива
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }

    // Вспомогательная функция для разделения массива и возвращения индекса опорного элемента
    static int partition(std::vector<int>& array, int low, int high) {
        int pivot = array[high]; // Опорный элемент
        int i = low - 1;         // Индекс меньшего элемента

        // Перебираем элементы от low до high-1
        for (int j = low; j <= high - 1; ++j) {
            // Если текущий элемент меньше или равен опорному
            if (array[j] <= pivot) {
                // Увеличиваем индекс меньшего элемента и меняем элементы местами
                ++i;
                std::swap(array[i], array[j]);
            }
        }

        // Меняем местами опорный элемент и элемент, стоящий после всех меньших элементов
        std::swap(array[i + 1], array[high]);
        return i + 1;
    }
};

int main() {
    // Пример использования быстрой сортировки
    setlocale(LC_ALL, "Russian");

    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    std::cout << "Исходный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Вызываем метод быстрой сортировки
    QuickSort::sort(array);

    std::cout << "Отсортированный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
