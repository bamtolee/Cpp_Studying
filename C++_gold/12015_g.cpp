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
    vector<int> lis;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if(i == 0) lis.push_back(cur);
        else
        {
            if(lis.back() < cur) lis.push_back(cur);
            else
            {
                int fi = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
                lis[fi] = cur;
            }
        }
    }
    cout << lis.size();
    return 0;
}