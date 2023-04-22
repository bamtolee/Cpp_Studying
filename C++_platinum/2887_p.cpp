#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
int p[100001];
vector<pair<int, int>> xV;
vector<pair<int, int>> yV;
vector<pair<int, int>> zV;
vector<pair<int, pair<int, int>>> el;

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(p[a] == a) return p[a];
    else return p[a] = findSet(p[a]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if(a != b)
    {
        if(a > b) p[a] = b;
        else p[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        xV.push_back({x, i});
        yV.push_back({y, i});
        zV.push_back({z, i});
        makeSet(i);
    }

    sort(xV.begin(), xV.end());
    sort(yV.begin(), yV.end());
    sort(zV.begin(), zV.end());
    for(int i = 1; i < n; i++)
    {
        el.push_back({xV[i].first - xV[i - 1].first, {xV[i - 1].second, xV[i].second}});
        el.push_back({yV[i].first - yV[i - 1].first, {yV[i - 1].second, yV[i].second}});
        el.push_back({zV[i].first - zV[i - 1].first, {zV[i - 1].second, zV[i].second}});
    }
    sort(el.begin(), el.end());

    int count = 0, i = 0;
    ll ret = 0;
    while(i < (int)el.size())
    {
        int from = el[i].second.first;
        int to = el[i].second.second;
        if(findSet(from) != findSet(to))
        {
            unionSet(from, to);
            ret += (ll)el[i].first;
            count++;
            if(count == n - 1) break;
        }
        i++;
    }
    cout << ret;
    return 0;
}