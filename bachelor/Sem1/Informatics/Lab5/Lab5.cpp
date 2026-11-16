#include <iostream>
#include <windows.h>

using namespace std;

void transpose(int n, int a[10][10], int b[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][i] = a[i][j];
        }
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int n;
    int a[10][10];
    int b[10][10];

    cout << "Введите размер матрицы: ";
    cin >> n;

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    transpose(n, a, b);

    cout << "\nТранспортированная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    bool sym = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                sym = false;
            }
        }
    }

    if (sym) {
        cout << "\nМатрица симметрическая" << endl;
    } else {
        cout << "\nМатрица не симметрическая" << endl;
    }

    return 0;
}