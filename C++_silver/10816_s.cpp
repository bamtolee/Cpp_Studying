#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    map<int, int> ma;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        map<int, int>::iterator iter;

        cin >> tmp;
        if(ma.find(tmp) == ma.end())
            ma.insert(make_pair(tmp, 1));
        else
        {
            iter = ma.find(tmp);
            iter->second++;
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        map<int, int>::iterator iter;

        cin >> tmp;
        if(ma.find(tmp) == ma.end()) cout << 0 << " ";
        else
        {
            iter = ma.find(tmp);
            cout << iter->second << " ";
        }
    }
    return 0;
}