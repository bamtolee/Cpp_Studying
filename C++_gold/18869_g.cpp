#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> universe[101];
vector<int> comp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            universe[i].push_back({tmp, j});
        }
    }
    
    for(int i = 0; i < m; i++)
        sort(universe[i].begin(), universe[i].end());
    for(int i = 0; i < m; i++)
    {
        int count = 0;
        comp[i].resize(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(j > 0 && universe[i][j].first == universe[i][j - 1].first)
                count++;
            comp[i][universe[i][j].second] = j - count;
        }
    }
    
    int ret = 0;
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = i + 1; j < m; j++)
        {
            bool flag = true;
            for(int k = 0; k < n; k++)
            {
                if(comp[i][k] != comp[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ret++;
        }
    }
    cout << ret;
    return 0;
}