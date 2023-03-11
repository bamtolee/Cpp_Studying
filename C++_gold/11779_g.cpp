#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<edge> vertex[1001];
vector<int> route;
int *p;
struct compare{
    bool operator()(edge a, edge b)
    {
        return a.second > b.second;
    }
};

int dijkstra(int n, int start, int end)
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
        int cur = tmp.first;
        pq.pop();
        if(d[cur] < tmp.second) continue;
        for(int i = 0; i < (int)vertex[cur].size(); i++)
        {
            int to = vertex[cur][i].first;
            if(vertex[cur][i].second + tmp.second < d[to])
            {
                p[to] = cur;
                d[to] = vertex[cur][i].second + tmp.second;
                pq.push({to, d[to]});
            }
        }
    }
    return d[end];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, start, end;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        vertex[u].push_back({v, d});
    }
    cin >> start >> end;
    p = new int[n + 1];
    fill(p, p + n + 1, 0);

    cout << dijkstra(n, start, end) << "\n";
    int ind = end;
    route.push_back(end);
    while(ind != start)
    {
        route.push_back(p[ind]);
        ind = p[ind];
    }
    cout << route.size() << "\n";
    for(int i = (int)route.size() - 1; i >= 0; i--)
        cout << route[i] << " ";
    return 0;
}
