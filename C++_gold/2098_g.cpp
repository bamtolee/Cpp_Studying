#include <iostream>
#include <algorithm>
using namespace std;

int cost[17][17];
int dp[70000][17];
int inf = 30000000;

int TSP(int n, int visited, int cur)
{
    if(visited == ((1 << n) - 1))
    {
        if(cost[cur][0] == 0) return inf;
        else return cost[cur][0];
    }
    // 이미 update 했으면
    if(dp[visited][cur] != -1)
        return dp[visited][cur];
    
    // 처음 memo update
    dp[visited][cur] = inf;
    for(int i = 0; i < n; i++)
    {
        if((visited & (1 << i)) != 0)
            continue;
        else if(cost[cur][i] == 0) continue;
        
        dp[visited][cur] = min(TSP(n, ((1 << i) | visited), i) + cost[cur][i],
                               dp[visited][cur]);
    }
    return dp[visited][cur];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    
    int ret = TSP(n, 1, 0);
    cout << ret;
    return 0;
}