#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[1001][1001];
int visit[1001][1001];
int cycle[1001][1001];
int ret;
bool flag;

void dfs(int r, int c)
{
    visit[r][c] = 1;
    int nr = r;
    int nc = c;
    if(map[r][c] == 'D') nr = r + 1;
    else if(map[r][c] == 'R') nc = c + 1;
    else if(map[r][c] == 'L') nc = c - 1;
    else if(map[r][c] == 'U') nr = r - 1;

    if(visit[nr][nc] == 0) dfs(nr, nc);
    else
    {
        if(cycle[nr][nc] == 0)
            ret++;
        flag = true;
        cycle[r][c] = 1;
        return;
    }
    if(flag) cycle[r][c] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
            map[i][j] = tmp[j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visit[i][j] == 0)
            {
                dfs(i, j);
                flag = false;
            }
        }
    }
    cout << ret;
    return 0;
}