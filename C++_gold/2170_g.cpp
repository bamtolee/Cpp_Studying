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
    vector<pair<int, int>> line;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        line.push_back({x, y});
    }

    sort(line.begin(), line.end());
    int left = line[0].first, right = line[0].second;
    int ret = right - left;
    for(int i = 1; i < n; i++)
    {
        int cl = line[i].first;
        int cr = line[i].second;
        if(cr <= right) continue;
        else if(cr > right && cl <= right)
        {
            ret += cr - right;
            right = cr;
        }
        else if(cl > right)
        {
            left = cl;
            right = cr;
            ret += right - left;
        }
    }
    cout << ret;
    return 0;
}