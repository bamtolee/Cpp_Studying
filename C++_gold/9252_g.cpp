#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1001][1001] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    int al = (int)a.length();
    int bl = (int)b.length();

    for(int i = 1; i <= al; i++)
    {
        for(int j = 1; j <= bl; j++)
        {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    stack<char> lcs;
    cout << dp[al][bl] << "\n";
    while(dp[al][bl] > 0)
    {
        if(a[al - 1] != b[bl - 1])
        {
            if(dp[al - 1][bl] > dp[al][bl - 1])
                al--;
            else bl--;
        }
        else
        {
            lcs.push(a[al - 1]);
            al--;
            bl--;
        }
    }
    while(!lcs.empty())
    {
        cout << lcs.top();
        lcs.pop();
    }
    return 0;
}