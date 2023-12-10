#include <iostream>
#include <string>
#include <stack>
#include <cctype>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

bool isValidExpression(const std::string& infix) {
    std::stack<char> brackets;
    for (char c : infix) {
        if (c == '(') {
            brackets.push(c);
        } else if (c == ')') {
            if (brackets.empty() || brackets.top() != '(') {
                return false; // Неправильное размещение скобок
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}

double evaluateExpression(const std::string& infix) {
    std::stack<double> values;
    std::stack<char> operators;

    for (char c : infix) {
        if (std::isspace(c)) {
            continue;
        } else if (std::isdigit(c)) {
            std::string number;
            while (std::isdigit(c) || c == '.') {
                number += c;
                c = getchar();
            }
            values.push(std::stod(number));
            continue;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                if (values.size() < 2) {
                    std::cerr << "Ошибка: неверное выражение." << std::endl;
                    return 0.0;
                }
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                if (op == '+') {
                    values.push(a + b);
                } else if (op == '-') {
                    values.push(a - b);
                } else if (op == '*') {
                    values.push(a * b);
                } else if (op == '/') {
                    if (b == 0) {
                        std::cerr << "Ошибка: деление на 0." << std::endl;
                        return 0.0;
                    }
                    values.push(a / b);
                }
            }
            if (!operators.empty()) {
                operators.pop(); // Убираем открывающую скобку
            }
        } else if (isOperator(c)) {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c)) {
                char op = operators.top();
                operators.pop();
                if (values.size() < 2) {
                    std::cerr << "Ошибка: неверное выражение." << std::endl;
                    return 0.0;
                }
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                if (op == '+') {
                    values.push(a + b);
                } else if (op == '-') {
                    values.push(a - b);
                } else if (op == '*') {
                    values.push(a * b);
                } else if (op == '/') {
                    if (b == 0) {
                        std::cerr << "Ошибка: деление на 0." << std::endl;
                        return 0.0;
                    }
                    values.push(a / b);
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        if (values.size() < 2) {
            std::cerr << "Ошибка: неверное выражение." << std::endl;
            return 0.0;
        }
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        if (op == '+') {
            values.push(a + b);
        } else if (op == '-') {
            values.push(a - b);
        } else if (op == '*') {
            values.push(a * b);
        } else if (op == '/') {
            if (b == 0) {
                std::cerr << "Ошибка: деление на 0." << std::endl;
                return 0.0;
            }
            values.push(a / b);
        }
    }

    if (values.size() != 1) {
        std::cerr << "Ошибка: неверное выражение." << std::endl;
        return 0.0;
    }

    return values.top();
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string input = "2+7*(3/9)-5=";

    if (!isValidExpression(input)) {
        std::cerr << "Ошибка: неверное размещение скобок." << std::endl;
        return 1;
    }

    input = input.substr(0, input.length() - 1);  // Убираем символ "="

    double result = evaluateExpression(input);

    std::cout << "Результат выражения: " << result << std::endl;

    return 0;
}
