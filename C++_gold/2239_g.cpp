#include <iostream>
#include <string>
using namespace std;

int sudoku[9][9];
bool fFlag;

bool check(int curR, int curC, int n)
{
    for(int i = 0; i < 9; i++)
    {
        if(i == curC) continue;
        if(sudoku[curR][i] == n) return false;
    }
    for(int i = 0; i < 9; i++)
    {
        if(i == curR) continue;
        if(sudoku[i][curC] == n) return false;
    }

    int nr = curR / 3;
    int nc = curC / 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(nr * 3 + i == curR && nc * 3 + j == curC) continue;
            if(sudoku[nr * 3 + i][nc * 3 + j] == n) return false;
        }
    }
    return true;
}

void bt(int curR, int curC)
{
    if(sudoku[curR][curC] == 0)
    {
        for(int i = 1; i <= 9; i++)
        {
            if(check(curR, curC, i))
            {
                sudoku[curR][curC] = i;
            
                int nc = curC + 1;
                int nr = curR;
                if(nc == 9)
                {
                    nc = 0;
                    nr += 1;
                    if(nr == 9) fFlag = true;
                }
                if(fFlag) return;
                bt(nr, nc);
                if(fFlag) return;
            }
        }
        sudoku[curR][curC] = 0;
    }
    else
    {
        int nc = curC + 1;
        int nr = curR;
        if(nc == 9)
        {
            nc = 0;
            nr += 1;
            if(nr == 9) fFlag = true;
        }
        if(fFlag) return;
        bt(nr, nc);
        if(fFlag) return;
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 9; j++)
            sudoku[i][j] = tmp[j] - '0';
    }

    bt(0, 0);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << sudoku[i][j];
        cout << "\n";
    }
    return 0;
}