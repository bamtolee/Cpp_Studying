#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret;

    while(1)
    {
        cin >> n;
        ret = 0;
        if(n == 0) break;
        else
        {
            for(int i = n + 1; i <= 2 * n; i++)
            {
                int j = 2;

                for(; j * j <= i; j++)
                    if(i % j == 0) break;
                if(j * j > i) ret++;
            }
            cout << ret << "\n";
        }
    }
    return 0;
}