#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> edge;
vector<edge> elGo[1001];
vector<edge> elBack[1001];
int dGo[1001];
int dBack[1001];
int inf = 100000000;

void dijkstraGo(int n, int x)
{
    fill(dGo, dGo + n + 1, inf);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    dGo[x] = 0;
    pq.push({dGo[x], x});

    while(!pq.empty())
    {
        edge cur = pq.top();
        pq.pop();
        int curC = cur.second;
        if(dGo[curC] < cur.first) continue;
        for(int i = 0; i < (int)elGo[curC].size(); i++)
        {
            int to = elGo[curC][i].second;
            if(dGo[to] > elGo[curC][i].first + cur.first)
            {
                dGo[to] = elGo[curC][i].first + cur.first;
                pq.push({dGo[to], to});
            }
        }
    }
}

void dijkstraBack(int n, int x)
{
    fill(dBack, dBack + n + 1, inf);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    dBack[x] = 0;
    pq.push({dBack[x], x});

    while(!pq.empty())
    {
        edge cur = pq.top();
        pq.pop();
        int curC = cur.second;
        if(dBack[curC] < cur.first) continue;
        for(int i = 0; i < (int)elBack[curC].size(); i++)
        {
            int to = elBack[curC][i].second;
            if(dBack[to] > elBack[curC][i].first + cur.first)
            {
                dBack[to] = elBack[curC][i].first + cur.first;
                pq.push({dBack[to], to});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        elBack[s].push_back({t, e});
        elGo[e].push_back({t, s});
    }

    dijkstraGo(n, x);
    dijkstraBack(n, x);
    int maxRet = 0;
    for(int i = 1; i <= n; i++)
        if(dGo[i] + dBack[i] > maxRet) maxRet = dGo[i] + dBack[i];
    cout << maxRet;
    return 0;
}