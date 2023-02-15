#include <iostream>
#include <queue>
using namespace std;

void arrRotation(int x, int y, int n, int m, int r, int **arr)
{
    if(n == 0 || m == 0) return;

    queue<int> tmpQ;

    for(int i = 0; i < m; i++)
        tmpQ.push(arr[x][y + i]);
    for(int i = 1; i < n; i++)
        tmpQ.push(arr[x + i][y + m - 1]);
    for(int i = 1; i < m; i++)
        tmpQ.push(arr[x + n - 1][y + m - 1 - i]);
    for(int i = 1; i < n - 1; i++)
        tmpQ.push(arr[x + n - 1 - i][y]);
    
    for(int i = 0; i < r % ((n + m - 2) * 2); i++)
    {
        int tmp = tmpQ.front();
        tmpQ.pop();
        tmpQ.push(tmp);
    }

    for(int i = 0; i < m; i++)
    {
        arr[x][y + i] = tmpQ.front();
        tmpQ.pop();
    }
    for(int i = 1; i < n; i++)
    {
        arr[x + i][y + m - 1] = tmpQ.front();
        tmpQ.pop();
    }
    for(int i = 1; i < m; i++)
    {
        arr[x + n - 1][y + m - 1 - i] = tmpQ.front();
        tmpQ.pop();
    }
    for(int i = 1; i < n - 1; i++)
    {
        arr[x + n - 1 - i][y] = tmpQ.front();
        tmpQ.pop();
    }
    arrRotation(x + 1, y + 1, n - 2, m - 2, r, arr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r, **arr;
    cin >> n >> m >> r;
    arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    arrRotation(0, 0, n, m, r, arr);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}