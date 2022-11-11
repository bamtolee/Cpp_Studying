#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;
    for(int i = m; i <= n; i++)
    {
        int j = 2;
        
        if(i == 1) continue;
        for(; j * j <= i; j++)
            if(i % j == 0) break;
        if(j * j > i) cout << i << "\n";
    }
    return 0;
}