#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> co;
int room[51][51];
int d[51][51];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void bfs(int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = 100000000;
    queue<co> q;
    q.push({0, 0});
    d[0][0] = 1;
    
    while(!q.empty())
    {
        co cur = q.front();
        int r = cur.first;
        int c = cur.second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(room[nr][nc] == 1)
            {
                if(d[nr][nc] > d[r][c])
                {
                    q.push({nr, nc});
                    d[nr][nc] = d[r][c];
                }
            }
            else
            {
                if(d[nr][nc] > d[r][c] + 1)
                {
                    q.push({nr, nc});
                    d[nr][nc] = d[r][c] + 1;
                }
            }
        }
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
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < n; j++)
            room[i][j] = tmp[j] - '0';
    }

    bfs(n);
    cout << d[n - 1][n - 1] - 1;
    return 0;
}