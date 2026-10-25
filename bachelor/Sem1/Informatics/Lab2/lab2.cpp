#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double epsilon = 0.0001;
    double sum = 0.0;
    int n = 1;

    double an = (2.0 * n - 1.0) / pow(2.0, n);

    while (an >= epsilon) {
        sum = sum + an;
        n = n + 1;
        an = (2.0 * n - 1.0) / pow(2.0, n);
    }

    cout << "Итоговая сумма ряда: " << sum << endl;
    cout << "Количество учтенных членов ряда: " << n - 1 << endl;

    return 0;
}
