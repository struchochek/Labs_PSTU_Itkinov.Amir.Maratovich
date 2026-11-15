#include <iostream>
using namespace std;

int fac(int a)
{
    if (a == 0)
    {
        return 0;
    }
    if (a == 1)
    {
        return 1;
    }
    if (a < 0){
        return a;
    }
    return a*fac(a-1);
    
}

int main()
{
    cout << fac(-2);
    return 0;
}
