#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

void bfs(int n, vector<list<int>> &ver, int r, int visit[])
{
    int count = 1, tmp;
    queue<int> q;

    visit[r] = count;
    count++;
    q.push(r);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(auto i : ver[tmp])
        {
            if(visit[i] == 0)
            {
                visit[i] = count;
                count++;
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
    
    int n, m, r, *visit, tmp1, tmp2;
    vector<list<int>> ver;

    cin >> n >> m >> r;
    visit = new int[n + 1];
    for(int i = 0; i <= n; i++) visit[i] = 0;
    ver.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        ver[tmp1].push_back(tmp2);
        ver[tmp2].push_back(tmp1);
    }
    for(int i = 1; i <= n; i++) ver[i].sort();
    bfs(n, ver, r, visit);
    for(int i = 1; i <= n; i++) cout << visit[i] << "\n";
    delete[] visit;
    return 0;
}