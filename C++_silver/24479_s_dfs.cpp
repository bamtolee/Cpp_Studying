#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 1;
int visit[100001] = {0};

void dfs(vector<vector<int>> &ver, int r)
{
    visit[r] = cnt;
    cnt++;
    for(auto i : ver[r])
        if(visit[i] == 0) dfs(ver, i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r, tmp1, tmp2;
    vector<vector<int>> ver;

    cin >> n >> m >> r;
    ver.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        ver[tmp1].push_back(tmp2);
        ver[tmp2].push_back(tmp1);
    }
    for(int i = 1; i <= n; i++) sort(ver[i].begin(), ver[i].end());
    dfs(ver, r);
    for(int i = 1; i <= n; i++) cout << visit[i] << "\n";
    return 0;
}