#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *a, *dp, max;

    cin >> n;
    a = new int[n];
    dp = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        max = 0;
        for(int j = 0; j < i; j++)
            if(a[i] > a[j] && dp[j] > max) max = dp[j];
        dp[i] = max + 1;
    }
    cout << *max_element(dp, dp + n);
    delete[] dp;
    delete[] a;
    return 0;
}