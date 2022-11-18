#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, **a, **dp;

    cin >> t;
    a = new int*[2];
    dp = new int*[2];
    while(t--)
    {
        cin >> n;
        a[0] = new int[n];
        a[1] = new int[n];
        dp[0] = new int[n];
        dp[1] = new int[n];
        for(int i = 0; i < n; i++) cin >> a[0][i];
        for(int i = 0; i < n; i++) cin >> a[1][i];
        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        dp[0][1] = dp[1][0] + a[0][1];
        dp[1][1] = dp[0][0] + a[1][1];
        for(int i = 2; i < n; i++)
        {
            dp[0][i] = max(dp[1][i - 1] + a[0][i], dp[1][i - 2] + a[0][i]);
            dp[1][i] = max(dp[0][i - 1] + a[1][i], dp[0][i - 2] + a[1][i]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
        delete[] a[0];
        delete[] a[1];
        delete[] dp[0];
        delete[] dp[1];
    }
    delete[] a;
    delete[] dp;
    return 0;
}