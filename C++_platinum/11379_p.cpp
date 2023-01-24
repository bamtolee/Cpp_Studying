#include <iostream>
using namespace std;

long long int visited[29][29] = {0};
long long int sol[28] = {0};

void dfs(int row, int column, int sol_index)
{
    sol[sol_index]++;
    visited[row][column] = 1;
    if(sol_index < 27)
    {
        if(!visited[row - 1][column] && row - 1 >= 0) dfs(row - 1, column, sol_index + 1);
        if(!visited[row + 1][column] && row + 1 <= 28) dfs(row + 1, column, sol_index + 1);
        if(!visited[row][column - 1] && column - 1 >= 0) dfs(row, column - 1, sol_index + 1);
        if(!visited[row][column + 1] && column + 1 <= 28) dfs(row, column + 1, sol_index + 1);
    }
    visited[row][column] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    int row = 0;
    int column = 0;
    int sol_index = 0;

    visited[0][0] = 1;

    dfs(row, column + 1, sol_index);
    for(int i = 0; i < 28; i++) cout << sol[i] << " ";
    */
    
    long long int answer[29] = {0, 1, 2, 5, 12, 30, 73, 183, 456, 1151, 2900, 7361, 18684, 47652,
                121584, 311259, 797311, 2047384, 5260692, 13542718, 34884239, 89991344,
                232282110, 600281932, 1552096361, 4017128206, 10401997092, 26957667445,
                69892976538};
    int a, b;
    long long int ret = 0;
    
    cin >> a >> b;
    for(int i = a; i <= b; i++)
        ret += answer[i];
    cout << ret;
    return 0;
}