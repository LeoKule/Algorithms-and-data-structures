#include <iostream>
#include <vector>

class MergeSort {
public:
    // ������� ���������� ��������
    static void sort(std::vector<int>& array) {
        if (array.size() > 1) {
            int mid = array.size() / 2;

            // ��������� ������ �� ��� ��������
            std::vector<int> left(array.begin(), array.begin() + mid);
            std::vector<int> right(array.begin() + mid, array.end());

            // ���������� ��������� ������ ��������
            sort(left);
            sort(right);

            // ���������� ��������������� ��������
            merge(array, left, right);
        }
    }

private:
    // ������� ��� ����������� ���� ��������������� ��������
    static void merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;

        // ���������� �������� �� ������ � ������� �������� � ���������� �� � �������������� ������
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        // ��������� ���������� �������� �� ������ ������� (���� ��� ����)
        while (i < left.size()) {
            array[k++] = left[i++];
        }

        // ��������� ���������� �������� �� ������� ������� (���� ��� ����)
        while (j < right.size()) {
            array[k++] = right[j++];
        }
    }
};

int main() {
    // ������ ������������� ���������� ��������
    setlocale(LC_ALL, "Russian");

    std::vector<int> array = {23, 4, 145, 55, 35, 90, 19, 10, 1000};

    std::cout << "�������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // �������� ����� ���������� ��������
    MergeSort::sort(array);

    std::cout << "��������������� ������:" << std::endl;
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
