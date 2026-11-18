#include <iostream>
#include <vector>
using namespace std;


void draw(vector<vector<int>>& rods, int n)
{
    int width = 15;

    for (int level = n - 1; level >= 0; level--)
    {
        for (int rod = 0; rod < 3; rod++)
        {
            string part;

            if (level < rods[rod].size())
            {
                int disk = rods[rod][level];
                int w = 2 * disk + 3;
                int space = (width - w) / 2;

                part = string(space, ' ') +
                       "+" + string(w - 2, '-') + "+" +
                       string(width - w - space, ' ');
            }
            else
            {
                part = string(width / 2, ' ') +
                       "|" +
                       string(width - width / 2 - 1, ' ');
            }

            cout << part << "   ";
        }

        cout << endl;
    }

    
    for (int i = 0; i < 3; i++)
        cout << string(width, '-') << "   ";

    cout << "\n\n";
}


void han(int size, int src, int dst,
         vector<vector<int>>& rods, int n)
{
    if (size == 1)
    {
        int disk = rods[src - 1].back();

        rods[src - 1].pop_back();
        rods[dst - 1].push_back(disk);

        draw(rods, n);
    }
    else
    {
        int buf = 6 - src - dst;

        han(size - 1, src, buf, rods, n);

        int disk = rods[src - 1].back();

        rods[src - 1].pop_back();
        rods[dst - 1].push_back(disk);

        draw(rods, n);

        han(size - 1, buf, dst, rods, n);
    }
}

int main()
{
    int n = 5;

    vector<vector<int>> rods(3);

    
    for (int i = n; i >= 1; i--)
        rods[0].push_back(i);

    
    draw(rods, n);

   
    han(n, 1, 3, rods, n);

    return 0;
}