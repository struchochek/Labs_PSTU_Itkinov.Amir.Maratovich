// #include <iostream>
// #include <string>

// struct Advertising {
//     int countob;
//     int click;
//     float srs;
// };
// int main()
// {
//     using namespace std;
//     Advertising dohod;
//     dohod.countob;
//     dohod.click;
//     dohod.srs;
//     cin >> dohod.countob >> dohod.click >> dohod.srs;
//     cout << dohod.countob*dohod.click*dohod.srs;
//     return 0;
// }

// #include <iostream>
// #include <string>

// struct mem {
//     std::string f;
//     std::string i;
//     std::string o;
//     int days;
//     float opl;
//     float prem;
// };

// int main()
// {
//     using namespace std;
//     mem rab;
//     cin >> rab.f >> rab.i >> rab.o >> rab.days >> rab.opl >> rab.prem;
//     cout << rab.f << ' ' << rab.i << ' ' << rab.o << " dohod: " << ((rab.days * rab.opl) + rab.prem);
// }
#include <iostream>
using namespace std;
template <typename t1>
t1 summ(t1 a, t1 b)
{
    return a + b;
}

void main()
{
    int a = 5;
    double b = 2;
    cout << summ(10, 2);
}