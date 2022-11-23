#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret, mid1, mid2, diff;

    cin >> n;
    if(n < 100) cout << n;
    else
    {
        ret = 99;
        for(int i = 100; i <= n; i++)
        {
            int tmp = i;

            mid2 = tmp % 10;
            tmp /= 10;
            mid1 = tmp % 10;
            tmp /= 10;
            diff = mid1 - mid2;
            while(tmp != 0)
            {
                mid2 = mid1;
                mid1 = tmp % 10;
                if(mid1 - mid2 != diff) break;
                tmp /= 10;
            }
            if(tmp == 0) ret++;
        }
        cout << ret;
    }
    return 0;
}