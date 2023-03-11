#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *yong;
    cin >> n;
    yong = new int[n];
    for(int i = 0; i < n; i++)
        cin >> yong[i];
    
    if(yong[n - 1] <= 0)
        cout << yong[n - 2] << " " << yong[n - 1];
    else if(yong[0] >= 0)
        cout << yong[0] << " " << yong[1];
    else
    {
        int ret = 2000000001, a = 0, b = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int j = lower_bound(yong + i + 1, yong + n, -yong[i]) - yong;
            if(j < n && ret > abs(yong[i] + yong[j]))
            {
                ret = abs(yong[i] + yong[j]);
                a = yong[i];
                b = yong[j];
            }
            if(j - 1 > i && ret > abs(yong[i] + yong[j - 1]))
            {
                ret = abs(yong[i] + yong[j - 1]);
                a = yong[i];
                b = yong[j - 1];
            }
        }
        cout << a << " " << b;
    }
    return 0;
}