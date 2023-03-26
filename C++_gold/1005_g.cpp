#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BTime[1001];
int inDegree[1001];
int visit[1001];
int w;
vector<int> adj[1001];
int result[1001];

void topoSort(int n)
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
            visit[i] = 1;
            result[i] = BTime[i];
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        int curTime = result[cur];
        q.pop();
        
        for(int i = 0; i < (int)adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            inDegree[next]--;
            result[next] = max(curTime + BTime[next], result[next]);
            if(visit[next] == 0 && inDegree[next] == 0)
            {
                q.push(next);
                visit[next] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        fill(inDegree, inDegree + n + 1, 0);
        fill(result, result + n + 1, 0);
        fill(visit, visit + n + 1, 0);
        for(int i = 1; i <= n; i++)
            cin >> BTime[i];
        for(int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            inDegree[y]++;
        }
        cin >> w;

        topoSort(n);
        cout << result[w] << "\n";
        for(int i = 1; i <= n; i++)
            adj[i].clear();
    }
    return 0;
}