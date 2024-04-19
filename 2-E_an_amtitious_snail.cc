/*
E. Амбициозная улитка
Ограничение времени 	5 секунд
Ограничение памяти 	256Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt
Домашний питомец мальчика Васи — улитка Петя. Петя обитает на бесконечном в обе стороны вертикальном столбе, который для удобства можно представить как числовую прямую. Изначально Петя находится в точке 0.

Вася кормит Петю ягодами. У него есть n ягод, каждая в единственном экземпляре. Вася знает, что если утром он даст Пете ягоду с номером i, то поев и набравшись сил, за остаток дня Петя поднимется на ai единиц вверх по столбу, но при этом за ночь, потяжелев, съедет на bi единиц вниз. Параметры различных ягод могут совпадать.

Пете стало интересно, а как оно там, наверху, и Вася взялся ему в этом помочь. Ближайшие n дней он будет кормить Петю ягодами из своего запаса таким образом, чтобы максимальная высота, на которой побывал Петя за эти n дней была максимальной. К сожалению, Вася не умеет программировать, поэтому он попросил вас о помощи. Найдите, максимальную высоту, на которой Петя сможет побывать за эти n дней и в каком порядке Вася должен давать Пете ягоды, чтобы Петя смог её достичь!

Формат ввода
В первой строке входных данных дано число n (1≤n≤5⋅105) — количество ягод у Васи. В последующих n строках описываются параметры каждой ягоды. В i+1 строке дано два числа ai и bi (0≤ai,bi≤109) — то, насколько поднимется улитка за день после того, как съест i ягоду и насколько опуститься за ночь.
Формат вывода
В первой строке выходных данных выведите единственное число — максимальную высоту, которую сможет достичь Петя, если Вася будет его кормить оптимальным образом. В следующей строке выведите n различных целых чисел от 1 до n — порядок, в котором Вася должен кормить Петю (i число в строке соответствует номеру ягоды, которую Вася должен дать Пете в i день чтобы Петя смог достичь максимальной высоты).

Пример 1
Ввод
3
1 5
8 2
4 4
Вывод
10
2 3 1 


Пример 2
Ввод
2
7 6
7 4
Вывод
10
2 1 


Примечания
Во втором примере изначально улитка находится на высоте 0. Пусть сначала Петя накормит её второй ягодой, а затем первой. После того как она съест вторую ягоду, за день она поднимется на 7 (и окажется на высоте 7), а за ночь опустится на 4 (и окажется на высоте 3). После того как она съест первую ягоду, за день она поднимется на 7 (и окажется на высоте 10), а за ночь опустится на 6 (и окажется на высоте 4).
Таким образом, максимальная высота, на которой побывает улитка при данном порядке кормления, равна 10. Нетрудно видеть, что если Петя накормит улитку сначала первой ягодой, а затем второй, то максимальная высота, на которой побывает улитка, будет меньше.

*/

#include <algorithm>
#include <iostream>
#include <vector>

struct Berry {
  int up = 0;
  int down = 0;
  int berry_id = 0;
};

int main() {
  int N = 0;
  std::cin >> N;
  std::vector<Berry> berries(N);

  for (int i = 0; i < N; ++i) {
    std::cin >> berries[i].up >> berries[i].down;
    berries[i].berry_id = i + 1;
  }

  // -4  56 60   - 5
  // -28 16 44   - 1
  // -25 13 38   - 3
  // -3  44 48   - 4
  // -51 6  57   - 6

  // std::sort(berries.begin(), berries.end(), [] (Berry& left,Berry& right) {
  //         if (left.up - left.down > 0 && right.up - right.down > 0) {
  //             return left.down > right.down;
  //         }
  //         else return left.up > right.up;
  //     });
  std::vector<int> positive, negative;
  int sum = 0;
  int index_max_up = -1;
  int index_max_down = -1;
  int max_positive = -1;
  int max_negative = -1;

  for (size_t i = 0; i < berries.size(); ++i) {
    if (berries[i].up - berries[i].down >= 0) {
      if (berries[i].down > max_positive) {
        if (max_positive >= 0) {
          positive.push_back(index_max_down);
        }
        max_positive = berries[i].down;
        index_max_down = berries[i].berry_id;
      } else {
        positive.push_back(berries[i].berry_id);
      }
    }
    if (berries[i].up - berries[i].down < 0) {
      if (berries[i].up > max_negative) {
        if (max_negative >= 0) {
          negative.push_back(index_max_up);
        }
        max_negative = berries[i].up;
        index_max_up = berries[i].berry_id;
      } else {
        negative.push_back(berries[i].berry_id);
      }
    }
  }
  if (index_max_down >= 0) {
    positive.push_back(index_max_down);
  }
  if (index_max_up >= 0) {
    negative.insert(negative.begin(), index_max_up);
  }
  positive.insert(positive.end(), negative.begin(), negative.end());
  long long int height = 0;
  long long int max_height = 0;
  for (int i = 0; i < N; ++i) {
    height += berries[positive[i] - 1].up;
    max_height = std::max(max_height, height);
    height -= berries[positive[i] - 1].down;
  }

  std::cout << max_height << std::endl;

  for (auto i : positive) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
