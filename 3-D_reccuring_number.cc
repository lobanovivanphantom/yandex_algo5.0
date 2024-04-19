/*
D. Повторяющееся число
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Вам дана последовательность измерений некоторой величины. Требуется определить, повторялась ли какое-либо число, причём расстояние между повторами не превосходило k.
Формат ввода

В первой строке задаются два числа n и k (1 ≤ n, k ≤ 105).

Во второй строке задаются n чисел, по модулю не превосходящих 109.
Формат вывода

Выведите YES, если найдется повторяющееся число и расстояние между повторами не превосходит k и NO в противном случае.
Пример 1
Ввод
4 2
1 2 3 1
Вывод
NO


Пример 2
Ввод
4 1
1 0 1 1
Вывод
YES


Пример 3
Ввод
6 2
1 2 3 1 2 3
Вывод
NO
*/

#include <iostream>
#include <vector>
#include <unordered_set>

std::string solution(int n, int m, const std::vector<int>& numbers) {
    std::unordered_set<int> info;
    int k = std::min(n, m + 1);
    for (int i = 0; i < k; ++i) {
        if (info.find(numbers[i]) != info.end()) {
            return "YES";
        }
        info.insert(numbers[i]);
    }
    if (m >= n) {
        return "NO";
    }
    for (int i = 0; i < std::max(n - k, 0); ++i) {
        info.erase(numbers[i]);
        if (info.find(numbers[i + k]) != info.end()) {
            return "YES";
        }
        info.insert(numbers[i + k]);
    }
    return "NO";
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::string res = solution(n, m, numbers);
    std::cout << res << std::endl;
    
    return 0;
}
