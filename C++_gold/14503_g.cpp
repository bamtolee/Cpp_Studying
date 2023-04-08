#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
pair<pair<int, int>, int> robot;
int map[51][51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cin >> robot.first.first >> robot.first.second >> robot.second;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];

    int ret = 0;
    while(true)
    {
        int curR = robot.first.first;
        int curC = robot.first.second;
        int curD = robot.second;
        if(map[curR][curC] == 0)
        {
            map[curR][curC] = 2;
            ret++;
        }

        bool vacFlag = false;
        for(int i = 0; i < 4; i++)
        {
            int nr = curR + dr[i];
            int nc = curC + dc[i];
            if(map[nr][nc] == 0)
                vacFlag = true;
        }

        if(vacFlag)
        {
            curD -= 1;
            if(curD == -1) curD = 3;
            if(map[curR + dr[curD]][curC + dc[curD]] == 0)
            {
                curR += dr[curD];
                curC += dc[curD];
            }
        }
        else
        {
            if(map[curR - dr[curD]][curC - dc[curD]] == 0 ||
            map[curR - dr[curD]][curC - dc[curD]] == 2)
            {
                curR -= dr[curD];
                curC -= dc[curD];
            }
            else if(map[curR - dr[curD]][curC - dc[curD]] == 1)
                break;
        }

        robot.first.first = curR;
        robot.first.second = curC;
        robot.second = curD;
    }
    cout << ret;
    return 0;
}