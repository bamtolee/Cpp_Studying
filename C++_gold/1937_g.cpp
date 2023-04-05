#include <iostream>
#include <algorithm>
using namespace std;

int forest[501][501];
int dist[501][501];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int n, int r, int c)
{
    if(dist[r][c] > 1) return dist[r][c];
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= n || nr < 0 || nc >= n || nc < 0)
            continue;
        if(forest[nr][nc] > forest[r][c])
            dist[r][c] = max(dfs(n, nr, nc) + 1, dist[r][c]);
    }
    return dist[r][c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ret = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
            dist[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tmp = dist[i][j];
            if(tmp == 1)
                tmp = dfs(n, i, j);
            dist[i][j] = tmp;
            if(tmp > ret) ret = tmp;
        }
    }
    cout << ret;
    return 0;
}