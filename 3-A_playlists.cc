/*
A. Плейлисты
Ограничение времени 	1.5 секунд
Ограничение памяти 	256Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt
Костя успешно прошел собеседование и попал на стажировку в отдел разработки сервиса «Музыка».

Конкретно ему поручили такое задание — научиться подбирать плейлист для группы друзей, родственников или коллег. При этом нужно подобрать такой плейлист, в который входят исключительно нравящиеся всем членам группы песни.

Костя очень хотел выполнить это задание быстро и качественно, но у него не получается. Помогите ему написать программу, которая составляет плейлист для группы людей.

Формат ввода
В первой строке расположено одно натуральное число n(1≤n≤2⋅105), где n – количество человек в группе.

В следующих 2⋅n строках идет описание любимых плейлистов членов группы. По 2 строки на каждого участника.

В первой из этих 2-х строк расположено число ki — количество любимых треков i-го члена группы. В следующей строке расположено ki строк через пробел — названия любимых треков i-го участника группы.

Каждый трек в плейлисте задан в виде строки, все строки уникальны, сумма длин строк не превосходит 2⋅106. Строки содержат большие и маленькие латинские буквы и цифры.

Формат вывода
Выведите количество, а затем сам список песен через пробел — список треков, которые нравятся каждому участнику группы. Ответ необходимо отсортировать в лексикографическом порядке!
Пример 1
Ввод
1
2
GoGetIt Life
Вывод
2
GoGetIt Life 


Пример 2
Ввод
2
2
Love Life
2
Life GoodDay	
Вывод
1
Life 
*/


#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

std::unordered_set<std::string> mix_sets(const std::unordered_set<std::string>& a_set, const std::unordered_set<std::string>& b_set) {
    std::unordered_set<std::string> res;
    for (const auto& x : a_set) {
        if (b_set.find(x) != b_set.end()) {
            res.insert(x);
        }
    }
    for (const auto& x : b_set) {
        if (a_set.find(x) != a_set.end()) {
            res.insert(x);
        }
    }
    return res;
}

std::pair<int, std::vector<std::string>> solution(const std::vector<std::vector<std::string>>& table) {
    if (table.empty()) {
        return {0, {}};
    }
    std::unordered_set<std::string> ans(table[0].begin(), table[0].end());
    for (size_t i = 1; i < table.size(); ++i) {
        ans = mix_sets(std::unordered_set<std::string>(table[i].begin(), table[i].end()), ans);
    }
    std::vector<std::string> res(ans.begin(), ans.end());
    std::sort(res.begin(), res.end());
    return {res.size(), res};
}


int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<std::string>> table;
    for (int i = 0; i < N; ++i) {
        int M;
        std::cin >> M;
        std::vector<std::string> user_songs(M);
        for (int j = 0; j < M; ++j) {
            std::cin >> user_songs[j];
        }
        table.push_back(user_songs);
    }
    auto result = solution(table);
    std::cout << result.first << std::endl;
    for (const auto& song : result.second) {
        std::cout << song << " ";
    }
    std::cout << std::endl;
    return 0;
}
