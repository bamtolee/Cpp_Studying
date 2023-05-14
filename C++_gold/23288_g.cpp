#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> co;
int map[21][21];
int diceInfor[4][3] = {{0, 2, 0}, {4, 1, 3}, {0, 5, 0}, {0, 6, 0}};
int diceDir;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int bfsScore(int cr, int cc, int n, int m)
{
    queue<co> q;
    int visit[21][21];
    int getScore = 0, check = map[cr][cc];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visit[i][j] = 0;

    q.push({cr, cc});
    visit[cr][cc] = 1;
    getScore += check;
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
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || visit[nr][nc] == 1)
                continue;
            if(map[nr][nc] != check) continue;
            getScore += check;
            q.push({nr, nc});
            visit[nr][nc] = 1;
        }
    }
    return getScore;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    
    int r = 0, c = 0, retScore = 0;
    for(int i = 0; i < k; i++)
    {
        int nr = r + dr[diceDir];
        int nc = c + dc[diceDir];       
        if(nr < 0 || nr >= n || nc < 0 || nc >= m)
        {
            diceDir -= 2;
            if(diceDir < 0) diceDir += 4;
            nr = r + dr[diceDir];
            nc = c + dc[diceDir];
        }
        if((diceDir & 1) == 0)
        {
            int tmp = diceInfor[3][1];
            diceInfor[3][1] = diceInfor[1][diceDir + dc[diceDir] + dc[diceDir]];
            diceInfor[1][diceDir + dc[diceDir] + dc[diceDir]] = diceInfor[1][diceDir + dc[diceDir]];
            diceInfor[1][diceDir + dc[diceDir]] = diceInfor[1][diceDir];
            diceInfor[1][diceDir] = tmp;
        }
        else
        {
            int tmp = diceInfor[3][1];
            diceInfor[3][1] = diceInfor[(3 - dr[diceDir]) % 4][1];
            diceInfor[(3 - dr[diceDir]) % 4][1] = diceInfor[(3 - dr[diceDir]) % 4 - dr[diceDir]][1];
            diceInfor[(3 - dr[diceDir]) % 4 - dr[diceDir]][1] = diceInfor[diceDir - 1][1];
            diceInfor[diceDir - 1][1] = tmp;
        }

        retScore += bfsScore(nr, nc, n, m);

        int check = map[nr][nc], bottom = diceInfor[3][1];
        if(bottom > check) diceDir = (diceDir + 1) % 4;
        else if(bottom < check)
        {
            diceDir -= 1;
            if(diceDir < 0) diceDir += 4;
        }
        r = nr;
        c = nc;
    }
    cout << retScore;
    return 0;
}