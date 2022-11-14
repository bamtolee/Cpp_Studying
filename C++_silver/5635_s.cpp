#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, max = 19000000, min = 20111111;
    int d, m, y, mid;
    string tmp, min_ret, max_ret;

    cin >> n;
    while(n--)
    {
        cin >> tmp >> d >> m >> y;
        mid = y * 10000 + m * 100 + d;
        if(mid > max) 
        {
            max = mid;
            max_ret = tmp;
        }
        if(mid < min)
        {
            min = mid;
            min_ret = tmp;
        }
    }
    cout << max_ret << "\n" << min_ret;
    return 0;
}