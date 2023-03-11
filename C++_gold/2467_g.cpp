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
        int i = n - 1, j = 0;
        int ret = 2000000001, a = 0, b = 0;
        while(j < i)
        {
            if(yong[j] + yong[i] < 0)
            {
                if(ret > abs(yong[j] + yong[i]))
                {
                    ret = abs(yong[j] + yong[i]);
                    a = yong[j];
                    b = yong[i];
                }
                j++;
            }
            else
            {
                if(ret > abs(yong[j] + yong[i]))
                {
                    ret = abs(yong[j] + yong[i]);
                    a = yong[j];
                    b = yong[i];
                }
                i--;
            }
        }
        cout << a << " " << b;
    }
    return 0;
}