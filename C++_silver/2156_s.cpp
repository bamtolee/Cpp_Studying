#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, *a, *dp;

    cin >> n;
    a = new int[n + 1];
    dp = new int[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n];
    delete[] a;
    delete[] dp;
    return 0;
}