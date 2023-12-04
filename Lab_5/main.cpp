#include <iostream>
#include <vector>
#include <algorithm>  // Для использования std::upper_bound и std::rotate

// Сортировка вставками:

int main() {
    // Изначальный вектор с элементами {12, 0, -21, 7}
    std::vector<int> targetArray{12, 0, -21, 7};

    // Строка с числами для добавления в вектор
    std::string randomNumbers = "087360513546";

    // Добавление чисел из строки в вектор
    for (char currentNumber : randomNumbers)
        targetArray.push_back(static_cast<int>(currentNumber - '0'));

    // Сортировка вставками
    for (int i = 1; i < targetArray.size(); ++i) {
        int currentNumber = targetArray[i];

        // Использование std::upper_bound для нахождения позиции вставки
        auto it = std::upper_bound(targetArray.begin(), targetArray.begin() + i, currentNumber);

        // Использование std::rotate для вставки элемента в нужное место
        std::rotate(it, targetArray.begin() + i, targetArray.begin() + i + 1);
    }

    // Вывод отсортированного вектора
    for (int i = 0; i < targetArray.size(); ++i) {
        std::cout << targetArray[i];
        if (i != targetArray.size() - 1) {
            std::cout << ", ";
        }
    }

    return 0;
}
