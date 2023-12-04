#include <iostream>
#include <vector>

class HeapSort {
public:
    // ���������� ������� � �������������� ������������� ���������� (heap sort)
    static void sort(std::vector<int>& array) {
        buildMaxHeap(array); // ��� 1: ������ ������������ ����

        // ��� 2: ��������������� ��������� ������������ ������� � ��������� ������ ����
        for (int i = array.size() - 1; i > 0; --i) {
            std::swap(array[0], array[i]); // �������� ������������ ������� � �����
            maxHeapify(array, 0, i); // ��������������� �������� ������������ ����
        }
    }

private:
    // ������ ������������ ���� �� ��������� �������
    static void buildMaxHeap(std::vector<int>& array) {
        int n = array.size();
        // �������� � ���������� ����, � �������� ���� �������
        for (int i = n / 2 - 1; i >= 0; --i) {
            maxHeapify(array, i, n); // ��������� ��������� ��� ������� ����, ������� �� �������� ������
        }
    }

    // ��������������� �������� ������������ ���� � �������� ���������
    static void maxHeapify(std::vector<int>& array, int i, int heapSize) {
        int largest = i;          // ������ ����� ���������
        int leftChild = 2 * i + 1; // ������ ������ �������
        int rightChild = 2 * i + 2;// ������ ������� �������

        // ���� ����� ������� ������ �����
        if (leftChild < heapSize && array[leftChild] > array[largest]) {
            largest = leftChild;
        }

        // ���� ������ ������� ������ �������� ����������� ��������
        if (rightChild < heapSize && array[rightChild] > array[largest]) {
            largest = rightChild;
        }

        // ���� ���������� ������� �� �������� ������
        if (largest != i) {
            // ����� ���������� ����� � ����������� ��������
            std::swap(array[i], array[largest]);
            // ���������� ��������� ��������� � ��������� � ���������� ���������
            maxHeapify(array, largest, heapSize);
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // �������� ������ ��� ����������
    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    // ������� �������� ������ �� �����
    std::cout << "�������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // �������� ����� ����������
    HeapSort::sort(array);

    // ������� ��������������� ������ �� �����
    std::cout << "��������������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
