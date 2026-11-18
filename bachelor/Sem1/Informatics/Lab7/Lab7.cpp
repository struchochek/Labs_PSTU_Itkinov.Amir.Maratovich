// #include <iostream> //7.1
// #include <string>
// #include <windows.h>
// using namespace std;
 
// string japanCalendar(int year) {
//     string colors[5] = {"зеленый", "красный", "желтый", "белый", "черный"};
//     string animals[12] = {"крыса", "корова", "тигр", "заяц", "дракон", "змея",
//                           "лошадь", "овца", "обезьяна", "курица", "собака", "свинья"};
//     int offset = (year - 1984) % 60;
//     if (offset < 0) offset += 60;
//     int colorIdx = (offset / 2) % 5;
//     int animalIdx = offset % 12;
//     return to_string(year) + " год - " + colors[colorIdx] + ", " + animals[animalIdx];
// }
 
// string japanCalendar(double yearApprox) {
//     int year = static_cast<int>(yearApprox + 0.5);
//     return japanCalendar(year);
// }
 
// int main() {
//     SetConsoleCP(65001);
//     SetConsoleOutputCP(65001);
//     cout << japanCalendar(1984) << endl;
//     cout << japanCalendar(2026) << endl;
//     cout << japanCalendar(2007.8) << endl;
//     return 0;
// }


#include <iostream>  //7.2
#include <cstdarg>
#include <windows.h>
using namespace std;
 
int findMin(int count, ...) {
    va_list args;
    va_start(args, count);
    int minVal = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < minVal) {
            minVal = val;
        }
    }
    va_end(args);
    return minVal;
}
 
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int m1 = findMin(5, 14, -3, 27, 0, 8);
    int m2 = findMin(10, 45, 12, -19, 88, 3, 7, -5, 100, 21, 9);
    int m3 = findMin(12, 10, 20, 30, 5, 15, 25, -42, 18, 99, 1, 4, 11);
 
    cout << "Минимум из 5 чисел: " << m1 << endl;
    cout << "Минимум из 10 чисел: " << m2 << endl;
    cout << "Минимум из 12 чисел: " << m3 << endl;
    return 0;
}