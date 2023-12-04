#include <iostream>
#include <vector>

class HeapSort {
public:
    // Сортировка массива с использованием пирамидальной сортировки (heap sort)
    static void sort(std::vector<int>& array) {
        buildMaxHeap(array); // Шаг 1: Строим максимальную кучу

        // Шаг 2: Последовательно извлекаем максимальный элемент и уменьшаем размер кучи
        for (int i = array.size() - 1; i > 0; --i) {
            std::swap(array[0], array[i]); // Помещаем максимальный элемент в конец
            maxHeapify(array, 0, i); // Восстанавливаем свойство максимальной кучи
        }
    }

private:
    // Строит максимальную кучу из заданного массива
    static void buildMaxHeap(std::vector<int>& array) {
        int n = array.size();
        // Начинаем с последнего узла, у которого есть потомки
        for (int i = n / 2 - 1; i >= 0; --i) {
            maxHeapify(array, i, n); // Применяем процедуру для каждого узла, который не является листом
        }
    }

    // Восстанавливает свойство максимальной кучи в заданном поддереве
    static void maxHeapify(std::vector<int>& array, int i, int heapSize) {
        int largest = i;          // Индекс корня поддерева
        int leftChild = 2 * i + 1; // Индекс левого потомка
        int rightChild = 2 * i + 2;// Индекс правого потомка

        // Если левый потомок больше корня
        if (leftChild < heapSize && array[leftChild] > array[largest]) {
            largest = leftChild;
        }

        // Если правый потомок больше текущего наибольшего элемента
        if (rightChild < heapSize && array[rightChild] > array[largest]) {
            largest = rightChild;
        }

        // Если наибольший элемент не является корнем
        if (largest != i) {
            // Обмен значениями корня и наибольшего элемента
            std::swap(array[i], array[largest]);
            // Рекурсивно применяем процедуру к поддереву с наибольшим элементом
            maxHeapify(array, largest, heapSize);
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Исходный массив для сортировки
    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    // Выводим исходный массив на экран
    std::cout << "Исходный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Вызываем метод сортировки
    HeapSort::sort(array);

    // Выводим отсортированный массив на экран
    std::cout << "Отсортированный массив:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
