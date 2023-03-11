#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<edge> spot[101];
int item[101];
int d[101];
int maxRet = 0;

struct compare{
    bool operator()(edge a, edge b) {
        return a.first > a.second;
    }
};

void dijkstra(int n, int t, int m)
{
    int inf = 2000000000;
    fill(d, d + n + 1, inf);

    priority_queue<edge, vector<edge>, compare> pq;
    d[t] = 0;
    pq.push({t, d[t]});

    while(!pq.empty())
    {
        edge tmp = pq.top();
        int cur = tmp.first;
        pq.pop();

        for(int i = 0; i < (int)spot[cur].size(); i++)
        {
            int to = spot[cur][i].first;
            if(d[to] > tmp.second + spot[cur][i].second)
            {
                d[to] = tmp.second + spot[cur][i].second;
                pq.push({to, d[to]});
            }
        }
    }
    int tmpSum = 0;
    for(int i = 1; i <= n; i++)
        if(d[i] <= m) tmpSum += item[i];
    if(maxRet < tmpSum) maxRet = tmpSum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        cin >> item[i];
    for(int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        spot[a].push_back({b, l});
        spot[b].push_back({a, l});
    }

    for(int i = 1; i <= n; i++)
        dijkstra(n, i, m);
    cout << maxRet;
    return 0;
}