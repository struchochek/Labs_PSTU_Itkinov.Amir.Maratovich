#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <windows.h>

using namespace std;

const int MAXLINE = 255;

void createFile(const char* filename) {
    FILE* f = fopen(filename, "w");
    const char* lines[10] = {
        "Абрикос растет в саду\n",
        "Второй дом номер 5\n",
        "Ананас лежит на столе\n",
        "Обычная строка без цифр\n",
        "Зима 2026 года\n",
        "Арбуз спелый и сладкий\n",
        "Кот спит на диване\n",
        "Телефон 89001112233\n",
        "Апельсин оранжевый\n",
        "Конец текстового файла\n"
    };
    for (int i = 0; i < 10; i++) {
        fputs(lines[i], f);
    }
    fclose(f);
}

void printFile(const char* filename) {
    FILE* f = fopen(filename, "r");
    char buf[MAXLINE];
    while (fgets(buf, MAXLINE, f) != NULL) {
        cout << buf;
    }
    fclose(f);
}

bool hasDigit(const char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit((unsigned char)s[i])) return true;
    }
    return false;
}

void copyFiles(const char* src, const char* dst) {
    FILE* in = fopen(src, "r");
    FILE* out = fopen(dst, "w");
    char buf[MAXLINE];
    while (fgets(buf, MAXLINE, in) != NULL) {
        if (!hasDigit(buf)) {
            fputs(buf, out);
        }
    }
    fclose(in);
    fclose(out);
}

int countStartsWithA(const char* filename) {
    FILE* f = fopen(filename, "r");
    char buf[MAXLINE];
    int count = 0;
    while (fgets(buf, MAXLINE, f) != NULL) {
        if (strncmp(buf, "А", strlen("А")) == 0 || buf[0] == 'A') {
            count++;
        }
    }
    fclose(f);
    return count;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    createFile("F1.txt");
    cout << "Файл F1:\n";
    printFile("F1.txt");

    copyFiles("F1.txt", "F2.txt");
    cout << "\nФайл F2:\n";
    printFile("F2.txt");

    cout << "\nКоличество строк на букву А в F2: " << countStartsWithA("F2.txt") << endl;

    return 0;
}