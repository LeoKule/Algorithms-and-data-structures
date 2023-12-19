#include <iostream>
#include <fstream>
#include <vector>
// Хеш функция:
// Суммируем ASCII-коды символов в строке и берём остаток от деления этой суммы на размер таблицы.
int hash(std::string s, int table_size)
{
    int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash += (int)(s[i]);
    }
    hash = hash % table_size;
    return hash;
}
//Открытая адресация:
//Если ячейка с вычисленным хешем уже занята, происходит поиск следующей свободной ячейки как вправо от текущей позиции, так и влево.
//Если свободная ячейка не найдена, строка вставляется в первую пустую ячейку, считая с начала таблицы.
void open_adress_fill(std::vector<std::string>& table, std::string str)
{
    int ind = hash(str, table.size());
    bool in_table = false;
    for (int i = 0; (i + ind) < table.size(); i++)
    {
        if (table[ind + i] == "")
        {
            table[ind + i] = str;
            in_table = true;
        }
        if (in_table) { break; }
    }
    if (!(in_table))
    {
        for (int i = 0; i < ind; i++)
        {
            if (table[i] == "")
            {
                table[i] = str;
                in_table = true;
            }
            if (in_table) { break; }
        }
    }
}
//Хеширование с использованием списков:
//Здесь используется двумерный вектор, чтобы представить таблицу с использованием списков.
//Каждый элемент вектора содержит список строк с одинаковым хешем.
void fill_with_lists(std::vector<std::vector<std::string>>& table, std::string str)
{
    int ind = hash(str, table.size());
    table[ind].push_back(str);
}

void print_table(std::vector<std::string>& table)
{
    for (int i = 0; i < table.size(); i++)
    {
        std::cout << i << " " << table[i] << std::endl;
    }
}
int main()
{
    std::ifstream in;
    //размер таблицы
    in.open("input.txt");
    std::string a;
    int size = 0;
    while (in >> a)
    {
        size++;
    }
    in.close();

    //вектор заданного размера для открытой адресации
    std::vector<std::string> table;
    for (int i = 0; i < size; i++)
    {
        table.push_back("");
    }
    //двумерный вектор заданного размера для таблицы со списками
    std::vector<std::vector<std::string>> table2;
    for (int i = 0; i < size; i++)
    {
        table2.push_back({});
    }
    // заполнение хеш таблиц
    in.open("input.txt");
    std::string cur;
    while (in >> cur)
    {
        open_adress_fill(table, cur);
        fill_with_lists(table2, cur);
    }
    in.close();

    // Вывод результатов в файлы:
    std::ofstream out1, out2;
    out1.open("result1.txt");
    out2.open("result2.txt");

    for (int i = 0; i < size; i++)
    {
        out1 << i << "   " << table[i] << '\n';
        out2 << i << "   ";
        for (int j = 0; j < table2[i].size(); j++)
        {
            out2 << table2[i][j] << "  ";
        }
        out2 << '\n';
    }

    out1.close();
    out2.close();

    // Вывод хешей для примера:
    std::cout << hash("guitar", 131) << " " << hash("basketball", 131) << " " << hash("quokka", 131);
}