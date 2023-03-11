#include <iostream>
#include <algorithm>
using namespace std;

int w[101];
int v[101];
int DP[101][100001] = {0};

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - w[i] >= 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[n][k];
    return 0;
}