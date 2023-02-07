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
        int n, m, w, *dis, *isqueue, *vcount, ret = 0;
        vector<pair<int, int>> edge[501];
        queue<int> spfa;

        cin >> n >> m >> w;
        dis = new int[n + 1];
        isqueue = new int[n + 1];
        vcount = new int[n + 1];
        for(int j = 0; j <= n; j++)
            isqueue[j] = 0;

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

        for(int j = 2; j <= n; j++)
            dis[j] = 10002;

        for(int j = 1; j <= n; j++)
        {
            if(ret == 1) break;
            for(int k = 0; k <= n; k++)
                vcount[k] = 0;
            
            dis[j] = 0;
            spfa.push(j);
            isqueue[j] = 1;
            vcount[j]++;
            while(!spfa.empty())
            {
                if(ret == 1) break;
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
                            vcount[infor.first]++;
                            if(vcount[infor.first] >= n)
                            {
                                ret = 1;
                                break;
                            }
                            isqueue[infor.first] = 1;
                            spfa.push(infor.first);
                        }
                    }
                }
            }
        }
        if(ret == 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        delete[] dis;
    }
    return 0;
}