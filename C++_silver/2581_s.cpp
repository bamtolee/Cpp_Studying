#include <iostream>
using namespace std;

int main()
{
    int m, n, sum = 0, min = 1;

    cin >> m >> n;
    for(int i = m; i <= n; i++)
    {
        if(i == 1) continue;
        int j = 2;
        for(; j * j <= i; j++)
            if(i % j == 0) break;
        if(j * j > i)
        {
            sum += i;
            if(min == 1) min = i;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << min;
    return 0;
}