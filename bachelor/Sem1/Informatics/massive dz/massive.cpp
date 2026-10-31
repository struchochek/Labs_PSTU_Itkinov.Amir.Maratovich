// 1z
// #include <iostream> 
// using namespace std;
// int main()
// {
//     int nums[10] = {1, 2, 2, 1, 3, 5, 5, 6, 7, 5};
//     int min, max, i, k, j, a, s;
//     max = 0;
//     min = 100;
//     a = 1;
//     s = 1;
//     for (i = 0; i < 10; i++)
//     {
//         if (max < nums[i])
//         {
//             max = nums[i];
//             k = i;
//             a = 1;
//         }
//         else if (max == nums[i])
//         {
//             a += 1;
//         }
//         if (min > nums[i])
//         {
//             min = nums[i];
//             j = i;
//             s = 1;
//         }
//         else if (min == nums[i])
//         {
//             s += 1;
//         }
//     }
//     cout << "min: " << min << " max: " << max << " ind min: " << j << " ind max: " << k << " kolvo min: " << s << " kolvo max: " << a;
//     return 0;
// }

// #pragma region 2z
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     bool f = false;
//     int n = 9;
//     for (int i = 0; i < n && !f; i++)
//     {
//         if (arr[i] >= arr[i+1])
//         {
//             f = true;
//         }
//     }
//     if (f == false){
//         cout << "sorted";
//     }
//     else {
//         cout << "unsorted";
//     }
// }
// #pragma endregion

// #pragma region 4z
// #include <iostream>
// using namespace std;
// int main()
// {
//     int s1, s2;
//     s1 = 0; s2 = 0;
//     int arr[2][5] = {
//         {1, -2, 3, -4, 5},
//         {-2, 3, -4, 5, -6}
//     };
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (arr[i][j] < 0)
//             {
//                 cout << arr[i][j] << ' ';
//                 if (i == 0)
//                 {
//                     s1 += arr[i][j];
//                 }
//                 else
//                 {
//                     s2 += arr[i][j];
//                 }
//             }
//             else
//             {
//                 cout << ' ' << arr[i][j] << ' ';
//                 if (i == 0)
//                 {
//                     s1 += arr[i][j];
//                 }
//                 else
//                 {
//                     s2 += arr[i][j];
//                 }
//             }           
//         }
//         cout << endl;
//     }
//     cout << "sum 1str: " << s1 << endl;
//     cout << "sum 2str: " << s2 << endl;
//     return 0;
// }
// pragma endregion


