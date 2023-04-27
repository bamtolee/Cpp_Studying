#include <iostream>
#include <string>
using namespace std;

char map[2002][2002];
char ret[2002][2002];
int visit[2002][2002];
int startR = -1, startC = -1;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool finishFlag = false;

void dfs(int r, int c, int n, int m)
{
    visit[r][c] = 1;
    ret[r][c] = '.';
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m)
        {
            if(!(r == startR && c == startC))
            {
                finishFlag = true;
                return;
            }
            else continue;
        }
        if(map[nr][nc] == '+' || visit[nr][nc] == 1)
            continue;
        dfs(nr, nc, n, m);
        if(finishFlag) return;
    }
    ret[r][c] = 0;
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
        {
            map[i][j] = tmp[j];
            if(map[i][j] == '.' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                && startR == -1)
            {
                startR = i;
                startC = j;
            }
        }
    }

    dfs(startR, startC, n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '+')
                cout << "+";
            else if(map[i][j] == '.' && ret[i][j] == '.')
                cout << ".";
            else
                cout << "@";
        }
        cout << "\n";
    }
    return 0;
}