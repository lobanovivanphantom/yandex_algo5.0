/*
B. Анаграмма?
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.
Формат ввода

Строки состоят из строчных латинских букв, их длина не превосходит 100000. Каждая записана в отдельной строке.
Формат вывода

Выведите "YES" если одна из строк является анаграммой другой и "NO" в противном случае.
Пример 1
Ввод
dusty
study	
Вывод
YES


Пример 2
Ввод
rat
bat
Вывод
NO
*/

#include <iostream>
#include <unordered_map>
#include <string>

std::string solution(const std::string& text1, const std::string& text2) {
    if (text1.size() != text2.size()) {
        return "NO";
    }
    
    std::unordered_map<char, int> d1;
    for (char t : text1) {
        d1[t]++;
    }
    
    std::unordered_map<char, int> d2;
    for (char t : text2) {
        d2[t]++;
    }
    
    return (d1 == d2) ? "YES" : "NO";
}


int main() {    
    std::string t1, t2;
    std::cin >> t1 >> t2;
    std::string res = solution(t1, t2);
    std::cout << res << std::endl;
    
    return 0;
}
