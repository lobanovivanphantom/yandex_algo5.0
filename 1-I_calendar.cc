/*
I. Расписание
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Как же Илье надоело учиться! Сначала школа, потом университет... Вот, наконец, наступил тот долгожданный день, когда Илье утром не надо ехать на учебу. Но, к несчастью для Ильи, оказалось, что после окончания университета начинается самое трудное — надо устраиваться на работу.

Во всемирно известной фирме «Goondex», в которую устроился Илья, принято очень много работать, в частности, для сотрудников установлена шестидневная рабочая неделя. Но, в качестве бонуса, «Goondex» каждый год предлагает своим сотрудникам выбрать любой день недели в качестве выходного. В свою очередь, оставшиеся шесть дней недели будут рабочими.

Илья сообразил, что с учётом государственных праздников (которые всегда являются выходными) с помощью правильного выбора выходного дня недели можно варьировать количество рабочих дней в году. Теперь он хочет знать, какой день недели ему следует выбрать в качестве выходного, чтобы отдыхать как можно больше дней в году, или, наоборот, демонстрировать чудеса трудолюбия, работая по максимуму.
Формат ввода

В первой строке входных данных находится одно целое число N (0 ≤ N ≤ 366) — количество государственных праздников.

Во второй строке содержится одно целое число year (1800 ≤ year ≤ 2100) — год, в который необходимо помочь Илье.

В каждой из последующих N строк расположено по паре чисел day month (day — целое число, month — слово, между day и month ровно один пробел), обозначающих, что день day месяца month является государственным праздником.

В последней строке расположено слово  — день недели первого января в год year.

Гарантируется, что все даты указаны корректно (в том числе указанный день недели первого января действительно является днём недели первого января соответствующего года year) и все дни государственных праздников различны.
Формат вывода

Выведите через пробел два дня недели — лучший и худший варианты дней недели для выходного (то есть дни недели, для которых достигается соответственно максимальное и минимальное количество выходных дней в году). Если возможных вариантов ответа несколько, выведите любой из них.

Пример 1
Ввод:
2
2015
1 January
8 January
Thursday
Вывод: Monday Thursday

Пример 2
Ввод:
3
2013
1 January
8 January
15 January
Tuesday
Вывод: Monday Tuesday

Пример 3
Ввод:
3
2013
6 February
13 February
20 February
Tuesday
Вывод: Tuesday Wednesday
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

struct Date {
    int day = 0;
    std::string month = "";
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

std::vector<int> CountWorkingDaysPerWeek(int year, int first_day) {
    std::vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(year)) {
        ++days_in_month[1];
    }
    std::vector<int> working_days_per_week(7, 0);
    for (int month = 0; month < 12; ++month) {
        int days = days_in_month[month];
        for (int day = 0; day < days; ++day) {
            ++working_days_per_week[first_day];
            first_day = (first_day + 1) % 7;
        }
    }
    return working_days_per_week;
}

int GetNumDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int rem_year = year % 100;
    int div_year = year / 100;
    int zeller = (day + (13 * (month + 1)) / 5 + rem_year + rem_year / 4 + div_year / 4 + 5 * div_year) % 7;
    zeller = (zeller + 5) % 7;
    return zeller;
}

int main() {
    int num_holiday = 0;
    std::cin >> num_holiday;
    int year = 0;
    std::cin >> year;
    std::vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(year)) {
        ++days_in_month[1];
    }
    
    std::map<std::string, int> months = {
    {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
    {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
    {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    std::map<std::string, int> days_of_week = {
    {"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thursday", 3},
    {"Friday", 4}, {"Saturday", 5}, {"Sunday", 6}
    };
    std::map<int,std::string> reverse_days_of_week = {
    {0,"Monday"}, {1,"Tuesday"}, {2, "Wednesday"}, {3, "Thursday"},
    {4, "Friday"}, {5, "Saturday"}, {6, "Sunday"}
    };

    std::vector<Date> holidays;
    Date holiday;
    for (int i = 0; i < num_holiday; ++i) {
        std::cin >> holiday.day >> holiday.month;
        holidays.push_back(holiday);
    }
    std::string first_day_year;
    std::cin >> first_day_year;
    std::vector<int> work_days = CountWorkingDaysPerWeek(year, days_of_week.at(first_day_year));
    for (int i = 0; i < num_holiday; ++i) {
    int day_of_week = GetNumDayOfWeek(year, months[holidays[i].month], holidays[i].day);
    --work_days[day_of_week];
}
    // for (auto i : work_days) {
    //     std::cout << i << std::endl;
    // }
    auto max_iter = std::max_element(work_days.begin(), work_days.end());
    auto min_iter = std::min_element(work_days.begin(), work_days.end());
    std::string max_work_day = reverse_days_of_week[std::distance(work_days.begin(), max_iter)];
    std::string min_work_day = reverse_days_of_week[std::distance(work_days.begin(), min_iter)];
    std::cout << max_work_day << " " << min_work_day << std::endl;
    return 0;
}
