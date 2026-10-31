//pragma region z1
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[7] = {5, 2, 3 ,4, 8, 9, 7};
//     for (int i = 1; i < 7; i++)
//     {
//         int j = i-1;
//         int y = arr[i];
//         bool f = false;
//         while ((j >= 0) && !f)
//         {
//             if (y < arr[j])
//             {
//                 arr[j+1] = arr[j];
//                 j -=1;
//             }
//             else
//             {
//                 f = true;
//             }
//         }
//         arr[j+1] = y;
//     }
//     for (int k = 0; k < 7; k++)
//     {
//         cout << arr[k] << ' ';
//     }
//     return 0;
// }
// pragma endregion

// pragma region z2
// #include <iostream>
// using namespace std;
// int main()
// {
//     int i, n, j;
//     int arr[7] = {5, 2, 3, 4, 8, 7, 9};
//     n = 7;
//     for (i = 0; i < n-1; i++)
//     {
//         int k = i;
//         for (j = i+1; j < n; j++)
//         {
//             if (arr[k] > arr[j])
//             {
//                 k = j;
//             }
//         }
//         int buffer = arr[k];
//         arr[k] = arr[i];
//         arr[i] = buffer;
//     }
//     for (int l = 0; l < n; l++)
//     {
//         cout << arr[l] << ' ';
//     }
//     return 0;
// }
// pragma endregion

//pragma region z3
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[7] = {5, 2, 3, 4, 8, 7, 9};
//     int n = 7;
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = n-1; j > i; j--)
//         {
//             if (arr[j - 1] > arr[j])
//             {
//                 int buffer = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = buffer;
//             }
//         }
//     }
//     for (int l = 0; l < n; l++)
//     {
//         cout << arr[l] << ' ';
//     }
//     return 0;
// }
// pragma endregion
