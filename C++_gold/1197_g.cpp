#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> edge;

int *p;

bool compare(edge a, edge b)
{
    return a.second < b.second;
}

void makeSet(int x)
{
    p[x] = x;
}

int findSet(int x)
{
    if(p[x] == x) return x;
    else return p[x] = findSet(p[x]);
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

    int v, e, ret = 0, cnt = 0, index = 0;
    vector<edge> el;

    cin >> v >> e;
    p = new int[v + 1];
    for(int i = 0; i <= v; i++)
        makeSet(i);
    for(int i = 0; i < e; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        el.push_back({{a, b}, c});
    }

    sort(el.begin(), el.end(), compare);
    while(true)
    {
        int from = findSet(el[index].first.first);
        int to = findSet(el[index].first.second);

        if(from != to)
        {
            unionSet(from, to);
            ret += el[index].second;
            cnt++;
            if(cnt == v - 1) break;
        }
        index++;
    }
    cout << ret;
    return 0;
}