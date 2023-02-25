#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    for(int tc = 0; tc < t; tc++)
    {
        int n, m, bInd = 0, ret = 0;
        vector<int> a;
        vector<int> b;

        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++)
        {
            while(true)
            {
                if(bInd < m && a[i] > b[bInd]) bInd++;
                else break;
            }
            ret += bInd;
        }
        cout << ret << "\n";
    }
    return 0;
}