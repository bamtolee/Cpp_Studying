#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> co;
typedef pair<co, int> ds;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int cost[150][150] = {0};
int d[150][150] = {0};

struct compare{
    bool operator()(ds a, ds b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int n)
{
    int inf = 2100000000;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = inf;
    
    priority_queue<ds, vector<ds>, compare> pq;
    d[0][0] = cost[0][0];
    pq.push({{0, 0}, d[0][0]});
    while(!pq.empty())
    {
        ds cur = pq.top();
        pq.pop();
        int curR = cur.first.first;
        int curC = cur.first.second;
        int curD = cur.second;
        if(d[curR][curC] < curD) continue;
        for(int i = 0; i < 4; i++)
        {
            int nr = curR + dr[i];
            int nc = curC + dc[i];
            if(nr < 0 && nr >= n && nc < 0 && nc >= n) continue;
            if(d[nr][nc] > curD + cost[nr][nc])
            {
                d[nr][nc] = curD + cost[nr][nc];
                pq.push({{nr, nc}, d[nr][nc]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> cost[i][j];
        
        dijkstra(n);
        cout << "Problem " << t << ": " << d[n - 1][n - 1] << "\n";
        t++;
    }
    return 0;
}