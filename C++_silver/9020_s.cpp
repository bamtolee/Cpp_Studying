#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int t, n, ret1, ret2;

    cin >> t;
    while(t--)
    {
        int mindif = 10000;

        cin >> n;
        for(int i = 2; i <= n / 2; i++)
        {
            int j = 2, k;

            for(; j * j <= i; j++)
                if(i % j == 0) break;
            if(j * j <= i) continue;
            k = n - i;
            j = 2;
            for(; j * j <= k; j++)
                if(k % j == 0) break;
            if(j * j <= k) continue;
            if(k - i < mindif)
            {
                ret1 = i;
                ret2 = k;
                mindif = k - i;
            }
        }
        cout << ret1 << " " << ret2 << "\n";
    }
    return 0;
}