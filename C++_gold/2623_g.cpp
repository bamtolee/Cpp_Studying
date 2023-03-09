#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> singer[1001];
vector<int> ret;
int *indegree;
int *visit;

void topologyS(int n)
{
    visit = new int[n + 1];
    fill(visit, visit + n + 1, 0);
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            visit[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ret.push_back(cur);
        for(int i = 0; i < singer[cur].size(); i++)
        {
            int to = singer[cur][i];
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
    indegree = new int[n + 1];
    fill(indegree, indegree + n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        int k;
        int a[2] = {0};
        cin >> k >> a[0];
        for(int j = 1; j < k; j++)
        {
            cin >> a[j % 2];
            singer[a[(j - 1) % 2]].push_back(a[j % 2]);
            indegree[a[j % 2]]++;
        }
    }

    topologyS(n);
    if(ret.size() != n) cout << 0;
    else
        for(int i = 0; i < n; i++)
            cout << ret[i] << "\n";
    return 0;
}