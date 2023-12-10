#include <iostream>
#include <vector>

class QuickSort {
public:
    // ������� ������� ����������
    static void sort(std::vector<int>& array) {
        quickSort(array, 0, array.size() - 1);
    }

private:
    // ��������������� ������� ������� ����������
    static void quickSort(std::vector<int>& array, int low, int high) {
        if (low < high) {
            // ��������� ������ � �������� ������ �������� ��������
            int pivotIndex = partition(array, low, high);

            // ���������� ��������� ��� �������� �������
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }

    // ��������������� ������� ��� ���������� ������� � ����������� ������� �������� ��������
    static int partition(std::vector<int>& array, int low, int high) {
        int pivot = array[high]; // ������� �������
        int i = low - 1;         // ������ �������� ��������

        // ���������� �������� �� low �� high-1
        for (int j = low; j <= high - 1; ++j) {
            // ���� ������� ������� ������ ��� ����� ��������
            if (array[j] <= pivot) {
                // ����������� ������ �������� �������� � ������ �������� �������
                ++i;
                std::swap(array[i], array[j]);
            }
        }

        // ������ ������� ������� ������� � �������, ������� ����� ���� ������� ���������
        std::swap(array[i + 1], array[high]);
        return i + 1;
    }
};

int main() {
    // ������ ������������� ������� ����������
    setlocale(LC_ALL, "Russian");

    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    std::cout << "�������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // �������� ����� ������� ����������
    QuickSort::sort(array);

    std::cout << "��������������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
