#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int tc;

    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        int n, m, w, *dis, *isqueue, ret = 1;
        vector<pair<int, int>> edge[501];
        queue<int> spfa;

        cin >> n >> m >> w;
        dis = new int[n + 1];
        isqueue = new int[n + 1];
        for(int i = 0; i <= n; i++)
            isqueue[i] = 0;
        for(int j = 0; j < m; j++)
        {
            int tmp1, tmp2, cost;

            cin >> tmp1 >> tmp2 >> cost;
            edge[tmp1].push_back(make_pair(tmp2, cost));
            edge[tmp2].push_back(make_pair(tmp1, cost));
        }
        for(int j = 0; j < w; j++)
        {
            int tmp1, tmp2, cost;

            cin >> tmp1 >> tmp2 >> cost;
            edge[tmp1].push_back(make_pair(tmp2, -1 * cost));
        }

        for(int k = 2; k <= n; k++)
            dis[k] = 10002;
        spfa.push(1);
        isqueue[1] = 1;
        while(!spfa.empty())
        {
            int tmp1 = spfa.front();

            spfa.pop();
            isqueue[tmp1] = 0;
            for(auto infor : edge[tmp1])
            {
                if(dis[tmp1] + infor.second < dis[infor.first])
                {
                    dis[infor.first] = dis[tmp1] + infor.second;
                    if(isqueue[infor.first] == 0)
                    {
                        isqueue[infor.first] = 1;
                        spfa.push(infor.first);
                    }
                }
            }
        }
        /*
        for(int j = 1; j <= n; j++)
        {
            for (int k = 0; k < edge[j].size(); k++)
            {
		        if (dis[edge[j][k].first] > edge[j][k].second + dis[j])
                {
                    ret = 0;
                    break;
                }
            }
		}
        */
        if(ret == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        delete[] dis;
    }
    return 0;
}