#include <iostream>
using namespace std;

void han(int size, int src, int dst)
{
    if (size == 1)
        cout << "bl:1" << ' ' << src << "=>" << dst << endl;
    
    else{
        int buf = 6 - src - dst;
        han(size-1, src, buf);
        cout << "bl:" << size << ' ' << src << "=>" << dst << endl;
        han(size-1, buf, dst);
    }
    
}
int main()
{
    han(5, 1, 3);
    return 0;
}