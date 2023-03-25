#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> port;
    vector<int> lis;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        port.push_back(x);
    }

    lis.push_back(port[0]);
    for(int i = 1; i < n; i++)
    {
        if(port[i] > lis[lis.size() - 1])
            lis.push_back(port[i]);
        else
        {
            int ind = lower_bound(lis.begin(), lis.end(), port[i]) - lis.begin();
            lis[ind] = port[i];
        }
    }
    cout << lis.size();
    return 0;
}