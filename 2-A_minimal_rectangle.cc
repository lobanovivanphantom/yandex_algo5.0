/*
A. Минимальный прямоугольник
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

На клетчатой плоскости закрашено K клеток. Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки.
Формат ввода

Во входном файле, на первой строке, находится число K (1 ≤ K ≤ 100). На следующих K строках находятся пары чисел Xi и Yi — координаты закрашенных клеток (|Xi|, |Yi| ≤ 109).
Формат вывода

Выведите в выходной файл координаты левого нижнего и правого верхнего углов прямоугольника.

Пример
Ввод
4
1 3
3 1
3 5
6 3
Вывод
1 1 6 5
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main () {
    int K = 0;
    int x = 0;
    int y = 0;
    std::vector<int>coor_x;
    std::vector<int>coor_y;
    std::cin >> K;
    for (int i = 0; i < K; ++i) {
        std::cin >> x >> y;
        coor_x.push_back(x);
        coor_y.push_back(y);
    }
    auto [minx,maxx] = std::minmax_element(coor_x.begin(),coor_x.end());
    auto [miny,maxy] = std::minmax_element(coor_y.begin(),coor_y.end());
    std::cout << *minx << " " << *miny << " " << *maxx << " " << *maxy << std::endl;


    return 0;
}
