#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int cost[1000][3];
    int ret[1000][3];

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> cost[i][j];
    ret[0][0] = cost[0][0];
    ret[0][1] = cost[0][1];
    ret[0][2] = cost[0][2];
    for(int i = 1; i < n; i++)
    {
        ret[i][0] = min(ret[i - 1][1] + cost[i][0], ret[i - 1][2] + cost[i][0]);
        ret[i][1] = min(ret[i - 1][0] + cost[i][1], ret[i - 1][2] + cost[i][1]);
        ret[i][2] = min(ret[i - 1][0] + cost[i][2], ret[i - 1][1] + cost[i][2]);
    }
    cout << min({ret[n - 1][0], ret[n - 1][1], ret[n - 1][2]});
    return 0;
}