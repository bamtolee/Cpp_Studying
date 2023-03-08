#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];
int *indegree;
int *semester;

void topologySort(int n)
{
    queue<int> q;

    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0) q.push(i);
        semester[i] = 1;
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++)
        {
            if(--indegree[v[cur][i]] == 0)
            {
                q.push(v[cur][i]);
                semester[v[cur][i]] = semester[cur] + 1;
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
    indegree= new int[n + 1];
    semester = new int[n + 1];
    fill(indegree, indegree + n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    topologySort(n);
    for(int i = 1; i <= n; i++)
        cout << semester[i] << " ";
    return 0;
}