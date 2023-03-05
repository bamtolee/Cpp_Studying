#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> tt;
vector<tt> v;

bool compare(tt a, tt b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), compare);
    int tmpEnd = v[0].second;
    ret++;
    for(int i = 1; i < n; i++)
    {
        if(v[i].first < tmpEnd) continue;
        else
        {
            tmpEnd = v[i].second;
            ret++;
        }
    }
    cout << ret;
    return 0;
}