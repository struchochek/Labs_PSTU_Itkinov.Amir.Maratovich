#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int arr[100];
    int n = 10;

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20 + 1;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int target;
    cout << "Введите значение для удаления: ";
    cin >> target;

    int new_n = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != target) {
            arr[new_n++] = arr[i];
        }
    }
    n = new_n;

    cout << "Массив после удаления элемента " << target << ":" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl << endl;

    int count_even = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) count_even++;
    }

    int old_n = n;
    n += count_even;

    int write_idx = n - 1;
    for (int i = old_n - 1; i >= 0; i--) {
        arr[write_idx--] = arr[i];
        if (arr[i] % 2 == 0) {
            arr[write_idx--] = 0;
        }
    }

    cout << "Итоговый массив:" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}