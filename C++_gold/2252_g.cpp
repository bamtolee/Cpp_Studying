#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[32001];
int visit[32001];
vector<int> adj[32001];
vector<int> ret;

void topologySort(int n)
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            visit[i] = 1;
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ret.push_back(cur);

        for(int i = 0; i < (int)adj[cur].size(); i++)
        {
            int to = adj[cur][i];
            indegree[to]--;
            if(visit[to] == 0 && indegree[to] == 0)
            {
                visit[to] = 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    topologySort(n);
    for(auto i : ret)
        cout << i << " ";
    return 0;
}