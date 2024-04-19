/*
Миша сидел на занятиях математики в Высшей школе экономики и решал следующую задачу: дано n целых чисел и нужно расставить между ними знаки + и ×
 так, чтобы результат полученного арифметического выражения был нечётным (например, между числами 5, 7, 2, можно расставить арифметические знаки следующим образом: 
5×7+2=37). Так как примеры становились все больше и больше, а Миша срочно убегает в гости, от вас требуется написать программу решающую данную задачу.
Формат ввода
В первой строке содержится единственное число n (2≤n≤105). Во второй строке содержится n целых чисел ai, разделённых пробелами (−109≤ai≤109). 
Гарантируется, что решение существует.
Формат вывода
В одной строке выведите n−1 символ + или ×, в результате применения которых получается нечётный результат. 
(Для вывода используйте соответственно знаки «+» (ASCII код—43) и «x» (ASCII код—120), без кавычек).
Пример 1
Ввод	            Вывод
3                   x+
5 7 2

Пример 2
Ввод	            Вывод
2                   +
4 -5

*/

#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> numbers(n, 0);
  std::vector<char> operators(n - 1);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  if (numbers.size() == 2 && numbers[0] % 2 != 0 && numbers[1] % 2 != 0) {
    std::cout << 'x' << std::endl;
  } else if ((numbers.size() == 2) &&
             (numbers[0] % 2 != 0 && numbers[1] % 2 == 0 ||
              numbers[0] % 2 == 0 && numbers[1] != 0))
    std::cout << '+' << std::endl;
  else {

    int count_odd = numbers[0] % 2;
    int first_odd = -1;

    for (int i = 0; i < n - 1; ++i) {
      if ((numbers[i] + numbers[i + 1]) % 2 == 0) {
        operators[i] = 'x';
      }

      else {
        operators[i] = '+';
        if (numbers[i + 1] % 2 != 0) {
          ++count_odd;
        }
      }
      if ((numbers[i] % 2 != 0) && first_odd == -1) {
        first_odd = i;
      }
    }
    if (count_odd % 2 != 0) {
      for (int i = 0; i < n - 1; ++i) {
        std::cout << operators[i];
      }
      std::cout << std::endl;
    } else {
      if (operators[first_odd] == '+') {
        operators[first_odd] = 'x';
      } else {
        operators[first_odd] = '+';
      }
      for (int i = 0; i < n - 1; ++i) {
        std::cout << operators[i];
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
