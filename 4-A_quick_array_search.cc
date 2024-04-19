/*
A. Быстрый поиск в массиве
Ограничение времени 	3 секунды
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt
Дан массив из N целых чисел. Все числа от −109 до 109.

Нужно уметь отвечать на запросы вида “Cколько чисел имеют значения отL доR?”.
Формат ввода
Число N (1≤N≤105). Далее N целых чисел.

Затем число запросов K (1≤K≤105).

Далее K пар чисел L,R (−109≤L≤R≤109) — собственно запросы.

Формат вывода
Выведите K чисел — ответы на запросы.

Пример
Ввод
5
10 1 10 3 4
4
1 10
2 9
3 4
2 2
Вывод
5 2 2 0 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int binary_search_first_x(int x, const std::vector<int>& mass) {
    if (mass.empty()) {
        return -1;
    }

    int l = 0;
    int r = mass.size() - 1;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (mass[m] >= x) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }

    if (r == -1) {
        return 0;
    }
    if (l == mass.size()) {
        return mass.size();
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> mass(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> mass[i];
    }
    std::sort(mass.begin(), mass.end());

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;
        int i_ = binary_search_first_x(l, mass);
        int j_ = binary_search_first_x(r + 1, mass);
        std::cout << j_ - i_ << " ";
    }

    return 0;
}
