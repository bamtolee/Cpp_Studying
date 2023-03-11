#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll *yong;
    cin >> n;
    yong = new ll[n];
    for(int i = 0; i < n; i++)
        cin >> yong[i];
    sort(yong, yong + n);

    if(yong[0] >= 0)
        cout << yong[0] << " " << yong[1] << " " << yong[2];
    else if(yong[n - 1] < 0)
        cout << yong[n - 3] << " " << yong[n - 2] << " " << yong[n - 1];
    else
    {
        ll ret = 3100000000;
        ll a = 0, b = 0, c = 0;
        for(int i = 0; i < n - 2; i++)
        {
            ll j = i + 1, k = n - 1;
            while(j < k)
            {
                ll tmpSum = yong[i] + yong[j] + yong[k];
                if(tmpSum < 0)
                {
                    if(abs(tmpSum) < ret)
                    {
                        ret = abs(tmpSum);
                        a = yong[i];
                        b = yong[j];
                        c = yong[k];
                    }
                    j++;
                }
                else
                {
                    if(abs(tmpSum) < ret)
                    {
                        ret = abs(tmpSum);
                        a = yong[i];
                        b = yong[j];
                        c = yong[k];
                    }
                    k--;
                }
            }
        }
        cout << a << " " << b << " " << c;
    }
    return 0;
}