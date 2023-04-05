#include <iostream>
using namespace std;

int busInfor[101][101];
int inf = 1000000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) busInfor[i][j] = 0;
            else busInfor[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(busInfor[a][b] > c)
            busInfor[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == k) continue;
            for(int j = 1; j <= n; j++)
            {
                if(j == k || i == j) continue;
                if(busInfor[i][j] > busInfor[i][k] + busInfor[k][j])
                    busInfor[i][j] = busInfor[i][k] + busInfor[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(busInfor[i][j] == inf) cout << 0 << " ";
            else cout << busInfor[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}