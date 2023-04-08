#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> co;
int field[1001][1001];
int visit[1001][1001][11];
int d[1001][1001];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void bfs(int n, int m, int k)
{
    queue<co> q;
    q.push({{0, 0}, 0});
    visit[0][0][0] = 1;
    d[0][0] = 1;
    if(n == 1 && m == 1)
    {
        cout << d[0][0];
        return;
    }

    while(!q.empty())
    {
        co cur = q.front();
        int cr = cur.first.first;
        int cc = cur.first.second;
        int ck = cur.second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            int nk = ck;
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if(field[nr][nc] == 0 && visit[nr][nc][nk] == 0)
            {
                visit[nr][nc][nk] = 1;
                q.push({{nr, nc}, nk});
                d[nr][nc] = d[cr][cc] + 1;
                if(nr == n - 1 && nc == m - 1)
                {
                    cout << d[nr][nc];
                    return;
                }
            }
            else if(field[nr][nc] == 1)
            {
                if(nk < k) nk++;
                else continue;
                if(visit[nr][nc][nk] == 0)
                {
                    visit[nr][nc][nk] = 1;
                    q.push({{nr, nc}, nk});
                    d[nr][nc] = d[cr][cc] + 1;
                }
            }
        }
    }
    cout << -1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
            field[i][j] = tmp[j] - '0';
    }

    bfs(n, m, k);
    return 0;
}