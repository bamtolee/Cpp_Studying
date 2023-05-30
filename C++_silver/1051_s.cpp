#include <iostream>
#include <string>
using namespace std;

int field[51][51];

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
            field[i][j] = tmp[j] - '0';
    }

    int maxRet = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 1; (k < n && k < m); k++)
            {
                if(i + k >= n || j + k >= m) break;
                if(field[i][j] == field[i + k][j] && field[i + k][j] == field[i][j + k]
                && field[i][j + k] == field[i + k][j + k] && k + 1 > maxRet)
                    maxRet = k + 1;
            }
        }
    }
    cout << maxRet * maxRet;
    return 0;
}