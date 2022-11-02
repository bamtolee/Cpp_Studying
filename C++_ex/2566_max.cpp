#include <iostream>
using namespace std;

int main()
{
    int i, j, max;
    int x, y;

    max = 0;
    x = 1; y = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp > max)
            {
                max = tmp;
                x = j + 1;
                y = i + 1;
            }
        }
    }
    cout << max << '\n';
    cout << y << ' ' << x << '\n';
    return 0;
}