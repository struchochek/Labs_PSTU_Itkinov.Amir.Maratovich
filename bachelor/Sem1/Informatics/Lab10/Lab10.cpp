#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int rows, cols, k;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    int **matr = new int*[rows];
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < rows; i++) {
        matr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matr[i][j];
        }
    }

    cout << "Введите номер добавляемой строки (от 1 до " << rows + 1 << "): ";
    cin >> k;
    k--;

    int **new_matr = new int*[rows + 1];
    cout << "Введите элементы новой строки:" << endl;
    for (int i = 0; i < rows + 1; i++) {
        new_matr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            if (i < k) new_matr[i][j] = matr[i][j];
            else if (i == k) cin >> new_matr[i][j];
            else new_matr[i][j] = matr[i - 1][j];
        }
    }

    cout << "\nРезультирующий массив:" << endl;
    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < cols; j++) {
            cout << new_matr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) delete[] matr[i];
    delete[] matr;

    for (int i = 0; i < rows + 1; i++) delete[] new_matr[i];
    delete[] new_matr;

    return 0;
}