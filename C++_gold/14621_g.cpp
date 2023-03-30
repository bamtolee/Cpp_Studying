#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> edge;
vector<edge> el;
char schoolType[1001];
int p[1001];

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(a == p[a]) return a;
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
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> schoolType[i];
        makeSet(i);
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        el.push_back({d, {u, v}});
    }
    
    int ret = 0, rCount = 0;
    sort(el.begin(), el.end());
    for(int i = 0; i < (int)el.size(); i++)
    {
        int u = el[i].second.first;
        int v = el[i].second.second;
        if(schoolType[u] != schoolType[v])
        {
            if(findSet(u) != findSet(v))
            {
                rCount++;
                unionSet(u, v);
                ret += el[i].first;
                if(rCount == n - 1) break;
            }
        }
    }
    if(rCount == n - 1) cout << ret;
    else cout << -1;
    return 0;
}