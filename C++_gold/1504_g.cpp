#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;
vector<edge> vertex[801];
struct compare {
    bool operator()(edge a, edge b)
    {
        return a.second > b.second;
    }
};

int dijkstra(int n, int start, int check)
{
    priority_queue<edge, vector<edge>, compare> pq;
    int *d = new int[n + 1];
    int inf = 2100000000;
    fill(d, d + n + 1, inf);

    d[start] = 0;
    pq.push({start, d[start]});
    while(!pq.empty())
    {
        edge tmp = pq.top();
        pq.pop();
        int cur = tmp.first;
        if(tmp.second > d[cur]) continue;
        for(int i = 0; i < vertex[cur].size(); i++)
        {
            int to = vertex[cur][i].first;
            if(vertex[cur][i].second + tmp.second < d[to])
            {
                d[to] = vertex[cur][i].second + tmp.second;
                pq.push({to, d[to]});
            }
        }
    }
    return d[check] == inf ? -1 : d[check];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    int req1, req2;

    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        vertex[u].push_back({v, d});
        vertex[v].push_back({u, d});
    }
    cin >> req1 >> req2;
    int road1 = dijkstra(n, 1, req1);
    int road2 = dijkstra(n, req1, req2);
    int road3 = dijkstra(n, req2, n);
    int road4 = dijkstra(n, 1, req2);
    int road5 = dijkstra(n, req2, req1);
    int road6 = dijkstra(n, req1, n);
    if(req1 == 1) road1 = 0;
    if(req2 == n) road3 = 0;
    if((road1 == -1 || road2 == -1 || road3 == -1) &&
        (road6 == -1 || road4 == -1 || road5 == -1)) cout << -1;
    else if(road1 == -1 || road2 == -1 || road3 == -1)
        cout << road4 + road5 + road6;
    else if(road6 == -1 || road4 == -1 || road5 == -1)
        cout << road1 + road2 + road3;
    else cout << min((road1 + road2 + road3), (road4 + road5 + road6));
    return 0;
}