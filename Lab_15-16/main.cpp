#include <iostream>
#include <vector>

#include <sstream>
#include <stack>

// Структура, представляющая узел бинарного дерева:
struct Node {
    int data;   // Значение узла
    Node* left;    // Указатель на левое поддерево
    Node* right;    // Указатель на правое поддерево

    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Функция для поиска индекса последней закрывающей скобки в левом поддереве:
int f_index(const std::string& s, int start_ind, int end_ind)
{
    if (start_ind > end_ind) { return -1; }
    std::stack<char> a;
    for (int i = start_ind; i <= end_ind; i++)
    {
        if (s[i] == '(') { a.push(s[i]); }
        else if (s[i] == ')')
        {
            if (a.top() == '(')
                a.pop();
            if (a.empty()) { return i; }
        }
    }
    return -1;
}
// Функция для построения бинарного дерева из строки:
Node* fillTree(const std::string& s, int start_ind, int end_ind)
{
    if (start_ind > end_ind) { return nullptr; }
    int val = 0;
    // Извлечение значения узла из строки:
    while (start_ind <= end_ind && (s[start_ind]-'0') >= 0 && (s[start_ind]-'0') <= 9)
    {
        val *= 10;
        val += s[start_ind]-'0';
        start_ind += 1;
    }
    // Создание узла с извлеченным значением
    auto* root = new Node(val);
    int ind = -1;
    // Поиск индекса последней закрывающей скобки левого поддерева
    if ((start_ind <= end_ind) && (s[start_ind] == '(')) { ind = f_index(s, start_ind, end_ind); }
    // Рекурсивное построение левого и правого поддеревьев
    if (ind != -1)
    {
        root->left = fillTree(s, start_ind + 1, ind - 1);
        root->right = fillTree(s, ind + 2, end_ind - 1);
    }
    return root;
}
// Рекурсивная функция для префиксного обхода дерева:
void preOrder(Node* node) {
    if (node == nullptr) { return; }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
// Рекурсивная функция для инфиксного обхода дерева:
void inOrder(Node* node) {
    if (node == nullptr) { return; }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}
// Рекурсивная функция для постфиксного обхода дерева:
void postOrder(Node* node) {
    if (node == nullptr) { return; }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}
// Обход дерева с использованием стека
// Использует стек для обхода узлов в порядке "корень-лево-право".
void stackOrder(Node* node)
{
    if (node == nullptr) { return; }
    std::stack<Node*> s;
    s.push(node);

    while (!s.empty())
    {
        auto temp = s.top();
        std::cout << temp->data << " ";

        s.pop();
        if (temp->right != nullptr) { s.push(temp->right); }
        if (temp->left != nullptr) { s.push(temp->left); }

    }
}

int main() {
// Строка, представляющая дерево в скобочной нотации:
    std::string str = "0(3(1)(6(4)(7)))(10(14)(13))";
    Node* root  = fillTree(str, 0, str.length() - 1);
// Вывод результатов различных обходов дерева:
    std::cout << "preOrder: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "inOrder: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "postOrder: ";
    postOrder(root);
    std::cout << std::endl;

    std::cout << "stackOrder: ";
    stackOrder(root);
    std::cout << std::endl;
}