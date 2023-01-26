#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(vector<list<int>> &vec, int visit[], int a, int b, int &ret, bool &flag)
{
    if(flag) return;
    visit[a] = 1;
    for(auto i : vec[a])
    {
        ret++;
        flag = i == b;
        if(visit[i] != 1) dfs(vec, visit, i, b, ret, flag);
        if(flag) break;
        ret--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, m, *visit, tmp1, tmp2, ret = 0;
    bool flag = false;
    vector<list<int>> vec;
    
    cin >> n >> a >> b >> m;
    vec.resize(n + 1);
    visit = new int[n + 1];
    fill_n(visit, n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        vec[tmp1].push_back(tmp2);
        vec[tmp2].push_back(tmp1);
    }
    dfs(vec, visit, a, b, ret, flag);
    if(!flag) ret = -1;
    cout << ret;
    return 0;
}