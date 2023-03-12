#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> edge;
vector<edge> el;
int p[1001];

bool compare(edge a, edge b)
{
    return a.second < b.second;
}

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
        if(a < b) p[b] = a;
        else p[a] = b;
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
        makeSet(i);
    for(int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        el.push_back({{from, to}, cost});
    }

    sort(el.begin(), el.end(), compare);
    int count = 0, ret = 0;
    for(int i = 0; i < (int)el.size(); i++)
    {
        edge cur = el[i];
        int from = cur.first.first;
        int to = cur.first.second;
        if(findSet(from) != findSet(to))
        {
            unionSet(from, to);
            ret += cur.second;
            count++;
            if(count == n - 1)
                break;
        }
    }
    cout << ret;
    return 0;
}