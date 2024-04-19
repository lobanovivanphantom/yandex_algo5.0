/*
E. Два из трех
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Вам даны три списка чисел. Найдите все числа, которые встречаются хотя бы в двух из трёх списков.
Формат ввода

Во входных данных описывается три списка чисел. Первая строка каждого описания списка состоит из длины списка n (1 ≤ n ≤ 1000). Вторая строка описания содержит список натуральных чисел, записанных через пробел. Числа не превосходят 109.
Формат вывода

Выведите все числа, которые содержатся хотя бы в двух списках из трёх, в порядке возрастания. Обратите внимание, что каждое число необходимо выводить только один раз.
Пример 1
Ввод
2
3 1
2
1 3
2
1 2
Вывод
1 3


Пример 2
Ввод
3
1 2 2
3
3 4 3
1
5
Вывод

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> find_common_numbers(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    std::unordered_set<int> set1(list1.begin(), list1.end());
    std::unordered_set<int> set2(list2.begin(), list2.end());
    std::unordered_set<int> set3(list3.begin(), list3.end());
    
    std::vector<int> common_numbers;
    
    for (int num : set1) {
        if (set2.count(num) || set3.count(num)) {
            common_numbers.push_back(num);
        }
    }
    
    for (int num : set2) {
        if ((set1.count(num) && !set3.count(num)) || (set3.count(num) && !set1.count(num))) {
            common_numbers.push_back(num);
        }
    }
    
    for (int num : set3) {
        if (set1.count(num) || set2.count(num)) {
            common_numbers.push_back(num);
        }
    }
    
    std::sort(common_numbers.begin(), common_numbers.end());
    common_numbers.erase(std::unique(common_numbers.begin(), common_numbers.end()), common_numbers.end()); // remove duplicates
    return common_numbers;
}

int main() {
    int n1, n2, n3;
    std::cin >> n1;
    std::vector<int> list1(n1);
    for (int i = 0; i < n1; ++i) {
        std::cin >> list1[i];
    }
    
    std::cin >> n2;
    std::vector<int> list2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> list2[i];
    }
    
    std::cin >> n3;
    std::vector<int> list3(n3);
    for (int i = 0; i < n3; ++i) {
        std::cin >> list3[i];
    }
    
    std::vector<int> result = find_common_numbers(list1, list2, list3);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
