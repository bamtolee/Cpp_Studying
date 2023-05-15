#include <iostream>
using namespace std;

int map[21][21];
int diceInfor[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int diceDir;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r, c, k;
    cin >> n >> m >> r >> c >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    
    for(int i = 0; i < k; i++)
    {
        cin >> diceDir;
        if(diceDir == 1) diceDir = 0;
        else if(diceDir == 4) diceDir = 1;
        int nr = r + dr[diceDir];
        int nc = c + dc[diceDir];       
        if(nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;
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

        if(map[nr][nc] == 0)
            map[nr][nc] = diceInfor[3][1];
        else
        {
            diceInfor[3][1] = map[nr][nc];
            map[nr][nc] = 0;
        }
        cout << diceInfor[1][1] << "\n";
        r = nr;
        c = nc;
    }
    return 0;
}