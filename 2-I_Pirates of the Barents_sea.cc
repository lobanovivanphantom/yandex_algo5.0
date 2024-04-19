/*
I. Пираты Баренцева моря
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt
Вася играет в настольную игру «Пираты Баренцева моря», которая посвящена морским битвам. Игровое поле представляет собой квадрат из N×N клеток, на котором расположено N кораблей (каждый корабль занимает одну клетку).

Вася решил воспользоваться линейной тактикой, для этого ему необходимо выстроить все N кораблей в одном столбце. За один ход можно передвинуть один корабль в одну из четырёх соседних по стороне клеток. Номер столбца, в котором будут выстроены корабли, не важен. Определите минимальное количество ходов, необходимых для построения кораблей в одном столбце. В начале и процессе игры никакие два корабля не могут находиться в одной клетке.
Формат ввода
В первой строке входных данных задаётся число N (1≤N≤100).

В каждой из следующих N строк задаются координаты корабля: сначала номер строки, затем номер столбца (нумерация начинается с единицы).
Формат вывода
Выведите одно число — минимальное количество ходов, необходимое для построения.

Пример
Ввод
3
1 2
3 3
1 1
Вывод
3

Примечания
В примере необходимо выстроить корабли в столбце номер 2. Для этого необходимо переставить корабль из клетки 3 3 в клетку 3 2 за один ход, а корабль из клетки 1 1 в клетку 2 2 за два хода. Существуют и другие варианты перестановки кораблей, однако ни в одном из них нет меньше трёх ходов.
*/


#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> distances = std::vector<int64_t>(n, 0);
    distances.reserve(n);
    int row, column;
    std::map<int, int> rowToCount;
    for (int i = 0; i < n; ++i) {
        std::cin >> row >> column;
        for (int j = 0; j < n; ++j) {
            distances[j] += std::abs(j + 1 - column);
        }
        rowToCount[row]++;
    }

    int minColumnIndex = 0;
    int minColumn = distances[0];
    for (int i = 1; i < n; ++i) {
        if (minColumn > distances.at(i)) {
            minColumn = distances.at(i);
            minColumnIndex = i;
        }
    }
    int64_t horizontalSteps = distances[minColumnIndex];

    std::vector<int> orderedRows;
    orderedRows.reserve(n);
    for (auto p : rowToCount) {
        row = p.first;
        for (int i = 0; i < p.second; ++i) {
            orderedRows.push_back(row);
        }
    }

    int64_t verticalSteps = 0;
    for (int i = 0; i < (int)orderedRows.size(); ++i) {
        verticalSteps += std::abs(orderedRows.at(i) - (i + 1));
    }

    std::cout << (horizontalSteps + verticalSteps);

    return 0;
}
