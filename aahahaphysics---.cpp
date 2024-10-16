#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// список названия вершин (индекс в ColumnName == индексу в table) для расстановки соответствий
const vector<string> ColumnName = { "O", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N" };

int main() {
    // переменная под приоритет вершины
    double PriorityNode = 0.2;

    // размерность таблицы
    int tableSize = 15;
    // cout << "Введите размерность таблицы:" << endl;
    // cin >> tableSize;


    // матрица расстояний между местоположениями, где первый double --- растояние между двумя пунктами, второй --- вероятность пойти в этот пункт
    vector<vector<pair<double, double>>> table(tableSize, vector<pair<double, double>>(tableSize));

    // открытие файла
    ifstream file("./input.csv");

    int row = 0;
    int column = 0;

    for (int i = 0; i <= tableSize; ++i) {
        column = 0;
        // создаем переменную под считывание строки
        string line, token;
        //считывание строки
        getline(file, line);

        int position = 0;

        // если строка не заголовок, то переносим в table
        if (i > 0) {
            // удаляем первую колонку с буквами
            position = line.find(",", position);
            line = line.substr(position + 1, line.length());
            // записываем длину между вершинами в матрицу
            while (line.find(",", position) != string::npos) {
                position = 0;
                // находим позицию следующей запятой - 1
                position = line.find(",", position);
                // если есть путь в эту вершину
                if (line.substr(0, position) != "-") {
                    // записываем число в переменную
                    int value = stoi(line.substr(0, position));
                    table[row][column] = make_pair(value, PriorityNode);
                }
                else {
                    table[row][column] = make_pair(0, PriorityNode);
                }
                column++;
                // обрезаем строчку до следующего числа
                line = line.substr(position + 1, line.length());
                position = 0;
            }
            cout << line.substr(0, line.length()) << endl;
             if (line.substr(0, line.length()) != "-") {
                 // записываем число в переменную
                 int value = stoi(line.substr(0, line.length()));
                 // записываем число в матрицу
                 if (value == 0) {
                     table[row][column] = make_pair(0, PriorityNode);
                 }
                 else {
                     table[row][column] = make_pair(value, PriorityNode);
                 }
             }
             else {
                 table[row][column] = make_pair(0, PriorityNode);
             }
            row++;
        }
    }

    for (int i = 0; i < tableSize; ++i) {
        for (int j = 0; j < tableSize; ++j) {
            cout << table[i][j].first << " ";
        }
        cout << endl;
    }


    // закрытие файла
    file.close();
}