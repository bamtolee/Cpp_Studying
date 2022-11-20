#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void dfs(int n, vector<list<int>> &ver, int v, int visit[])
{
    visit[v] = 1;
    cout << v << " ";
    for(auto i : ver[v])
        if(visit[i] != 1) dfs(n, ver, i, visit);
}

void bfs(int n, vector<list<int>> &ver, int v, int visit[])
{
    queue<int> q;
    int tmp;

    visit[v] = 1;
    cout << v << " ";
    q.push(v);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(auto i : ver[tmp])
        {
            if(visit[i] != 1)
            {
                visit[i] = 1;
                cout << i << " ";
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, v, *visit, tmp1, tmp2;
    vector<list<int>> ver;

    cin >> n >> m >> v;
    visit = new int[n + 1];
    ver.resize(n + 1);
    for(int i = 0; i <= n; i++) visit[i] = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        ver[tmp1].push_back(tmp2);
        ver[tmp2].push_back(tmp1);
    }
    for(int i = 1; i <= n; i++) ver[i].sort();
    dfs(n, ver, v, visit);
    cout << "\n";
    for(int i = 0; i <= n; i++) visit[i] = 0;
    bfs(n, ver, v, visit);
    delete[] visit;
    return 0;
}