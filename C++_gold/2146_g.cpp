#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> bridge;
int islandCount;
int ret;
int map[101][101];
int dfsVisit[101][101];
int bfsVisit[101][101][101];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(int n)
{
    queue<bridge> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] > 0)
            {
                for(int k = 0; k < 4; k++)
                {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n)
                        continue;
                    if(map[ni][nj] == 0)
                    {
                        q.push({{i, j}, map[i][j]});
                        break;
                    }
                }
            }
        }
    }
    
    while(!q.empty())
    {
        int qs = (int)q.size();
        ret++;
        for(int i = 0; i < qs; i++)
        {
            bridge cur = q.front();
            q.pop();
            for(int j = 0; j < 4; j++)
            {
                int nr = cur.first.first + dr[j];
                int nc = cur.first.second + dc[j];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n
                  || map[nr][nc] == cur.second
                  || bfsVisit[nr][nc][cur.second] == 1)
                    continue;
                if(map[nr][nc] > 0)
                    return;
                bfsVisit[nr][nc][cur.second] = 1;
                q.push({{nr, nc}, cur.second});
            }
        }
    }
}

void dfs(int n, int r, int c)
{
    dfsVisit[r][c] = 1;
    map[r][c] = islandCount;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < n
          && dfsVisit[nr][nc] == 0 && map[nr][nc] == 1)
            dfs(n, nr, nc);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dfsVisit[i][j] == 0 && map[i][j] == 1)
            {
                islandCount++;
                dfs(n, i, j);
            }
        }
    }
    
    bfs(n);
    cout << ret - 1;
    return 0;
}