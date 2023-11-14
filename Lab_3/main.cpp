#include <iostream>
#include <windows.h>
//На вход дается одно число х, нужно вывести все числа от 1 до х, удовлетворяющие условию:
//3^K*5^L*7^M=xi
//где K, L, M - натуральные числа или могут быть равны 0.

// Функция целочисленного возведения в степень
unsigned int powInt(unsigned int base, unsigned int exponent) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
//Эта функция проверяет условие 3^K*5^L*7^M <= x
bool degreeCheck(unsigned int K, unsigned int L, unsigned int M, unsigned int x) {
    unsigned int result = powInt(3, K) * powInt(5, L) * powInt(7, M);
    if (result <= x) {
        std::cout << result << ": " << K << ", " << L << ", " << M << std::endl;
        return true;
    }
    return false;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int x{};
    std::cout << "Введите значение x\n>>>";
    std::cin >> x;

    if (x == 0) {
        std::cout << "Нет решений для x = 0." << std::endl;
        return 0;
    }

    unsigned int K{0};
    unsigned int L{0};
    unsigned int M{0};
    unsigned int countSolutions = 0;

    while (powInt(3, K) * powInt(5, L) * powInt(7, M) <= x) {
        while (powInt(3, K) * powInt(5, L) * powInt(7, M) <= x) {
            while (powInt(3, K) * powInt(5, L) * powInt(7, M) <= x) {
                if (degreeCheck(K, L, M, x)) {
                    countSolutions++;
                }
                M++;
            }
            L++;
            M = 0;
        }
        K++;
        L = 0;
    }

    if (countSolutions == 0) {
        std::cout << "Решения не найдены." << std::endl;
    }

    return 0;
}
