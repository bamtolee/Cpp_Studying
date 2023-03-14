#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> edge;
vector<int> p;
vector<edge> el;

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(p[a] == a) return a;
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

    int n, m, ret = 0;
    cin >> n >> m;
    p.resize(n + 1);
    for(int i = 1; i <= n; i++)
        makeSet(i);
    for(int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        el.push_back({cost, {from, to}});
    }

    sort(el.begin(), el.end());
    int count = 0;
    for(int i = 0; i < (int)el.size(); i++)
    {
        edge cur = el[i];
        int from = findSet(cur.second.first);
        int to = findSet(cur.second.second);
        int cost = cur.first;
        if(from != to)
        {
            ret += cost;
            count++;
            unionSet(from, to);
            if(count == n - 2) break;
        }
    }
    cout << ret;
    return 0;
}