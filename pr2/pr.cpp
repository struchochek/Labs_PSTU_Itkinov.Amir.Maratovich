#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void Fillarray(int* const arr, const int size)//заполнение д.м. рандомно
{
    for (int i = 0; i < size; i++)
        arr[i] = rand()%10;
}
void Showarray(const int* const arr, const int size)//вывод д.м.
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void pushback(int *&arr, int &size, int const value) //добавить в конец
{
    int *arrz = new int[size+1];
    for (int i = 0; i < size; i++)
        arrz[i] = arr[i];
    arrz[size] = value;
    delete[]arr;
    arr = arrz;
    size++;
    delete[]arrz;
}

void popback(int *&arr, int  &size) //убрать последний элемент
{
    size--;
    int *newarr = new int[size];
    for (int i = 0; i < size; i++)
        newarr[i] = arr[i];
    delete[]arr;
    arr = newarr;
    delete[]newarr;
}

void kolvo_str(string stroka)//подсчёт слов в строке
{
    int count = 1;
    for (int i = 0; i < stroka.size(); i++)
    {
        if (stroka[i] == ' ')
            count++;
    }
    cout << "колво слов в строке: " << count;
}

// int main()    //копирование массива
// {
//     int size = 10;
//     int *arr1 = new int[size];
//     int *arr2 = new int[size];
//     Fillarray(arr1, size);
//     Showarray(arr1, size);
//     Fillarray(arr2, size);
//     Showarray(arr2, size);
//     delete[]arr1;
//     arr1 = new int[size];
//     for (int i = 0; i < size; i++)
//         arr1[i] = arr2[i];
//     Showarray(arr1, size);
//     return 0;
//     delete[]arr1;
//     delete[]arr2;
// }

// #pragma region //Указатель на функцию в качестве параметра
// string f1()
// {
//     return "1";
// }
//
//
// string f2()
// {
//     return "2";
// }
//
//
// void showinfo(string (*f)())
// {
//     cout << f() << endl;
// }
//
//
// int main()    
// {
//     showinfo(f1);
//     return 0;
// } 
// #pragma endregion

// #pragma region //шаблоны функций
// template <typename t2, typename t3>
// t2 summ(t2 a, t3 b)
// {
//     return a + b;
// }
// void main()
// {
//     int a = 5;
//     double b = 2.5;
//     cout << summ(a, b);
// }
// #pragma endregion

// #pragma region //классы
// class human
// {
// public:
//     int age;
//     int weight;
//     string name;
//     void print()
//     {
//         cout << name << "\t" << age << "\t" << weight << "\t" << endl;
//     }
// };
// int main()
// {
//     human me;
//     me.age = 17;
//     me.weight = 55;
//     me.name = "AMIR";
//     me.print();
//     return 0;
// }
// #pragma endregion








// int main()    
// {
//     SetConsoleCP(65001);
//     SetConsoleOutputCP(65001);
//     int(*fpointer)(int b);
//     fpointer = f2;
//     fpointer(10);
//     return 0;
// } 

