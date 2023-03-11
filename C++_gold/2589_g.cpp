#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> co;
int map[50][50];
int d[50][50] = {0};
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int bfs(int n, int m, int r, int c)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = 0;
    int visit[50][50] = {0};
    int ret = 0;
    queue<co> q;
    q.push({r, c});
    visit[r][c] = 1;

    while(!q.empty())
    {
        co cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if(visit[nr][nc] == 0 && map[nr][nc] == 'L')
                {
                    visit[nr][nc] = 1;
                    q.push({nr, nc});
                    d[nr][nc] = d[cur.first][cur.second] + 1;
                    if(ret < d[nr][nc]) ret = d[nr][nc];
                }
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ret = 0;
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
            if(map[i][j] == 'L')
            {
                int tmp = bfs(n, m, i, j);
                if(ret < tmp) ret = tmp;
            }
        }
    }
    cout << ret;
    return 0;
}