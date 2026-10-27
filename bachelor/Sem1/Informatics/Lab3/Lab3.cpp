#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double a = 0.1;
    double b = 0.8;
    int steps = 10;
    double h = (b - a) / steps;
    double epsilon = 0.0001;
    double pi = 3.14159265358979323846;

   
    for (double x = a; x <= b + h / 2; x += h) {
        
        
        double Y = (x * sin(pi / 4.0)) / (1.0 - 2.0 * x * cos(pi / 4.0) + x * x);

       
        double SN = 0.0;
        for (int n = 1; n <= 40; n++) {
            double an = pow(x, n) * sin(n * pi / 4.0);
            SN = SN + an;
        }

        double SE = 0.0;
        int n_eps = 1;
        double an_eps = x * sin(pi / 4.0);

        while (abs(an_eps) >= epsilon) {
            SE = SE + an_eps;
            n_eps = n_eps + 1;
            an_eps = pow(x, n_eps) * sin(n_eps * pi / 4.0);
        }

        cout << "X=" << x << "\tSN=" << SN << "\tSE=" << SE << "\tY=" << Y << endl;
    }

    return 0;
}