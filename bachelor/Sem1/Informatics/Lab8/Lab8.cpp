#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct Buyer {
    char fullName[100];
    char address[150];
    char phone[25];
    char cardNumber[25];
};

void checkError(bool condition, const char* msg) {
    if (condition) {
        perror(msg);
        exit(1);
    }
}

Buyer makeBuyer(int num) {
    Buyer b;
    sprintf(b.fullName, "Покупатель %d", num);
    sprintf(b.address, "Адрес %d", num);
    sprintf(b.phone, "8900000000%d", num);
    sprintf(b.cardNumber, "111100000000000%d", num);
    return b;
}

void createFile(const char* filename, int count) {
    FILE* f = fopen(filename, "wb");
    checkError(!f, "Ошибка создания файла");
    for (int i = 1; i <= count; i++) {
        Buyer b = makeBuyer(i);
        checkError(fwrite(&b, sizeof(Buyer), 1, f) != 1, "Ошибка записи");
    }
    fclose(f);
}

void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");
    checkError(!f, "Ошибка открытия файла");
    Buyer b;
    int i = 1;
    cout << "\n--- Содержимое файла ---\n";
    while (fread(&b, sizeof(Buyer), 1, f) == 1) {
        cout << i++ << ". " << b.fullName << " | " << b.address
             << " | " << b.phone << " | " << b.cardNumber << '\n';
    }
    checkError(ferror(f), "Ошибка чтения");
    fclose(f);
}

bool shouldDelete(int index, int count) {
    return index < count;
}

void deleteFirst(const char* filename, int count) {
    FILE* f = fopen(filename, "rb");
    FILE* temp = fopen("temp.dat", "wb");
    checkError(!f || !temp, "Ошибка открытия файлов");

    Buyer b;
    int index = 0;
    while (fread(&b, sizeof(Buyer), 1, f) == 1) {
        if (!shouldDelete(index++, count)) {
            checkError(fwrite(&b, sizeof(Buyer), 1, temp) != 1, "Ошибка записи");
        }
    }
    fclose(f);
    fclose(temp);
    remove(filename);
    rename("temp.dat", filename);
}

void appendRecords(const char* filename, int startNum, int count) {
    FILE* f = fopen(filename, "ab");
    checkError(!f, "Ошибка открытия файла");
    for (int i = 0; i < count; i++) {
        Buyer b = makeBuyer(startNum + i);
        checkError(fwrite(&b, sizeof(Buyer), 1, f) != 1, "Ошибка записи");
    }
    fclose(f);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const char* file = "buyers.dat";

    createFile(file, 5);
    printFile(file);

    cout << "\nУдаление 3 первых записей...\n";
    deleteFirst(file, 3);
    printFile(file);

    cout << "\nДобавление 3 записей в конец...\n";
    appendRecords(file, 6, 3);
    printFile(file);

    return 0;
}