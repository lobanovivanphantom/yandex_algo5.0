/*
C. Удаление чисел
Ограничение времени 	1 секунда
Ограничение памяти 	256Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt
Дан массив a из n чисел. Найдите минимальное количество чисел, после удаления которых попарная разность оставшихся чисел по модулю не будет превышать 1, то есть после удаления ни одно число не должно отличаться от какого-либо другого более чем на 1.
Формат ввода
Первая строка содержит одно целое число n (1≤n≤2⋅105) — количество элементов массива a.
Вторая строка содержит n целых чисел a1,a2,…,an (0≤ai≤105) — элементы массива a.
Формат вывода
Выведите одно число — ответ на задачу.
Пример 1
Ввод
5
1 2 3 4 5
Вывод
3


Пример 2
Ввод
10
1 1 2 3 5 5 2 2 1 5
Вывод
4
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, int> quantity_dict(const std::vector<int>& numbers) {
    std::unordered_map<int, int> info;
    for (int x : numbers) {
        info[x]++;
    }
    return info;
}

int solution(int n, const std::vector<int>& numbers) {
    std::unordered_map<int, int> info_number = quantity_dict(numbers);
    std::vector<int> sorted_numbers;
    for (const auto& pair : info_number) {
        sorted_numbers.push_back(pair.first);
    }
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    int i = 0;
    int res = n - info_number[sorted_numbers[0]];
    for (size_t j = 1; j < sorted_numbers.size(); ++j) {
        if (sorted_numbers[j] - sorted_numbers[i] > 1) {
            int sum = 0;
            for (size_t k = i; k < j; ++k) {
                sum += info_number[sorted_numbers[k]];
            }
            res = std::min(res, n - sum);
            while (i <= j && sorted_numbers[j] - sorted_numbers[i] > 1) {
                ++i;
            }
        }
    }

    while (i < sorted_numbers.size() && sorted_numbers.back() - sorted_numbers[i] > 1) {
        ++i;
    }
    if (i < sorted_numbers.size()) {
        int sum = 0;
        for (size_t k = i; k < sorted_numbers.size(); ++k) {
            sum += info_number[sorted_numbers[k]];
        }
        res = std::min(res, n - sum);
    }
    return res;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    int res = solution(n, numbers);
    std::cout << res << std::endl;
    
    return 0;
}
