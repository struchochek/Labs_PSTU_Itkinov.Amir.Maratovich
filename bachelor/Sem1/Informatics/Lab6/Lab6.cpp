#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char str[256];
    cout << "Введите строку (до 255 символов, в конце точка):" << endl;
    cin.getline(str, 256);

    char digits[256];
    int digits_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            digits[digits_count] = str[i];
            digits_count++;
        }
    }

    for (int i = 0; i < digits_count - 1; i++) {
        for (int j = 0; j < digits_count - i - 1; j++) {
            if (digits[j] < digits[j + 1]) {
                char temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }

    int digit_idx = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            str[i] = digits[digit_idx];
            digit_idx++;
        }
    }

    cout << "\nИтоговая строка:" << endl;
    cout << str << endl;

    return 0;
}