#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int DP[1001][1001] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    for(int i = 1; i <= (int)a.length(); i++)
    {
        for(int j = 1; j <= (int)b.length(); j++)
        {
            if(a[i - 1] == b[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }
    cout << DP[(int)a.length()][int(b.length())];
    return 0;
}