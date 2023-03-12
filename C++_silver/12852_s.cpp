#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *d, *p;
    cin >> n;
    d = new int[n + 1];
    p = new int[n + 1];
    fill(d, d + n + 1, 0);
    p[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(i % 3 == 0 && i % 2 != 0)
        {
            if(d[i / 3] < d[i - 1])
            {
                d[i] = d[i / 3] + 1;
                p[i] = i / 3;
            }
            else
            {
                d[i] = d[i - 1] + 1;
                p[i] = i - 1;
            }
        }
        else if(i % 2 == 0 && i % 3 != 0)
        {
            if(d[i / 2] < d[i - 1])
            {
                d[i] = d[i / 2] + 1;
                p[i] = i / 2;
            }
            else
            {
                d[i] = d[i - 1] + 1;
                p[i] = i - 1;
            }
        }
        else if(i % 6 == 0)
        {
            if(d[i / 2] < d[i / 3])
            {
                d[i] = d[i / 2] + 1;
                p[i] = i / 2;
            }
            else
            {
                d[i] = d[i / 3] + 1;
                p[i] = i / 3;
            }
            if(d[i] - 1 > d[i - 1])
            {
                d[i] = d[i - 1] + 1;
                p[i] = i - 1;
            }
        }
        else
        {
            d[i] = d[i - 1] + 1;
            p[i] = i - 1;
        }
    }
    cout << d[n] << "\n";

    vector<int> route;
    route.push_back(n);
    while(n != 1)
    {
        n = p[n];
        route.push_back(n);
    }
    for(auto i : route)
        cout << i << " ";
    return 0;
}