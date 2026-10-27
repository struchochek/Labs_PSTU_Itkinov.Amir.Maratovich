#include <iostream>

using namespace std;

int main() {
    double a = 100.0;
    double b = 0.001;

    double ab = a + b;
    double ab4 = ab * ab * ab * ab;

    double chislitel = ab4 - (a * a * a * a + 4 * a * a * a * b + 6 * a * a * b * b);
    double znamenatel = 4 * a * b * b * b + b * b * b * b;

    double result = chislitel / znamenatel;

    cout << result << endl;

    int n = 5;
    int m = 3;

    int op1 = n++ - m;
    cout << op1 << " " << n << endl;

    bool op2 = m-- > n;
    cout << op2 << " " << m << endl;
    
    bool op3 = n-- > m;
    cout << op3 << " " << n << endl;

    return 0;
}
// #include <iostream>

// using namespace std;

// int main() {
//     double a = 100.0;
//     double b = 0.001;

//     double ab = a + b;
//     double ab4 = ab * ab * ab * ab;

//     double chislitel = ab4 - (a * a * a * a + 4 * a * a * a * b + 6 * a * a * b * b);
//     double znamenatel = 4 * a * b * b * b + b * b * b * b;

//     double result = chislitel / znamenatel;

//     cout << result << endl;

//     int n = 5;
//     int m = 3;

//     int op1 = n++ - m;
//     cout << op1 << " " << n << endl;

//     bool op2 = m-- > n;
//     cout << op2 << " " << m << endl;
    
//     bool op3 = n-- > m;
//     cout << op3 << " " << n << endl;

//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main() {
//     int n = 5;
//     int m = 3;
//     int op1 = n++ - m; // 1 шаг
//     cout << op1 << " " << n << endl;
//     bool op2 = m-- > n; // 2 шаг
//     cout << op2 << " " << m << endl;
//     bool op3 = n-- > m; // 3 шаг
//     cout << op3 << " " << n << endl;

//     return 0;
// }