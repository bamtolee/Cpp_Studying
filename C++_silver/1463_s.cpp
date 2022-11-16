#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, tmp, tmp1, tmp2;
    vector<int> v;

    cin >> n;
    v.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            v.push_back(0);
            continue;
        }
        if(i % 2 != 0 && i % 3 != 0) tmp = v[i - 1] + 1;
        else if(i % 6 == 0)
        {
            tmp1 = v[i / 2] + 1;
            tmp2 = v[i / 3] + 1;
            tmp = min(tmp1, tmp2);
        }
        else if(i % 2 == 0)
        {
            tmp1 = v[i - 1] + 1;
            tmp2 = v[i / 2] + 1;
            tmp = min(tmp1, tmp2);
        }
        else if(i % 3 == 0)
        {
            tmp1 = v[i / 3] + 1;
            tmp2 = v[i - 1] + 1;
            tmp = min(tmp1, tmp2);
        }
        v.push_back(tmp);
    }
    cout << v[n];
    return 0;
}