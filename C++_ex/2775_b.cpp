#include <iostream>
using namespace std;

int main()
{
    int t, k, n, **dp;

    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        dp = new int*[k + 1];
        for(int i = 0; i <= k; i++)
            dp[i] = new int[n + 1];
        for(int i = 0; i <= n; i++)
            dp[0][i] = i;
        for(int i = 1; i <= k; i++)
        {
            dp[i][0] = 0;
            for(int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        cout << dp[k][n] << "\n";
        for(int i = 0; i <= k; i++) delete[] dp[i];
        delete[] dp;
    }
    return 0;
}