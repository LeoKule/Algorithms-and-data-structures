#include <iostream>
#include <vector>

void cocktailSort(std::vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        // Проход слева направо
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Если не было обменов, то массив уже отсортирован
        if (!swapped)
            break;

        // Уменьшаем "end", так как самый большой элемент уже находится на правильной позиции
        --end;

        // Проход справа налево
        swapped = false;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Увеличиваем "start", так как самый маленький элемент уже находится на правильной позиции
        ++start;
    }
}

int main() {
    std::vector<int> sequence = {4, 2, 7, 1, 9, 5, 3};

    std::cout << "Original sequence: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }

    cocktailSort(sequence);

    std::cout << "\nSorted sequence: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }

    return 0;
}
