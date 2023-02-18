#include <iostream>
using namespace std;

void findNum(int num, int bingo[5][5])
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(bingo[i][j] == num) bingo[i][j] = 0;
}

int bingoCheck(int bingo[5][5])
{
    int ret = 0;
    for(int i = 0; i < 5; i++)
    {
        int j = 0;
        for(; j < 5; j++)
            if(bingo[i][j] != 0) break;
        if(j == 5) ret++;
    }
    for(int i = 0; i < 5; i++)
    {
        int j = 0;
        for(; j < 5; j++)
            if(bingo[j][i] != 0) break;
        if(j == 5) ret++;
    }
    int i = 0;
    for(; i < 5; i++)
        if(bingo[i][i] != 0) break;
    if(i == 5) ret++;
    i = 4;
    for(; i >= 0; i--)
        if(bingo[i][4 - i] != 0) break;
    if(i == -1) ret++;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int bingo[5][5], bingoLine = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> bingo[i][j];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int tmp;
            cin >> tmp;
            if(bingoLine >= 3) continue;
            findNum(tmp, bingo);
            bingoLine = bingoCheck(bingo);
            if(bingoLine >= 3)
                cout << i * 5 + j + 1;
        }
    }
    return 0;
}