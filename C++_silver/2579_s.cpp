#include <iostream>
#include <algorithm>
using namespace std;

int stair[301];
int ret[301][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> stair[i];
    
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
            ret[i][1] = stair[i];
        else
        {
            ret[i][2] = ret[i - 1][1] + stair[i];
            ret[i][1] = max(ret[i - 2][1], ret[i - 2][2]) + stair[i];
        }
    }
    cout << max(ret[n][1], ret[n][2]);
    return 0;
}