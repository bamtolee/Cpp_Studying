#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ret = 0;
int visit[100001];
int p[100001];
bool findFlag = false;
queue<int> q;

void bfs(int n, int k)
{
    fill(visit, visit + 100001, 0);
    fill(p, p + 100001, 0);
    q.push(n);
    visit[n] = 1;
    p[n] = n;
    
    while(!q.empty())
    {
        int qSize = q.size();
        ret++;
        for(int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            if(cur == k)
            {
                ret--;
                findFlag = true;
                break;
            }
            q.pop();

            if(cur - 1 >= 0 && visit[cur - 1] == 0)
            {
                visit[cur - 1] = 1;
                q.push(cur - 1);
                p[cur - 1] = cur;
            }
            if(cur + 1 <= 100000 && visit[cur + 1] == 0)
            {
                visit[cur + 1] = 1;
                q.push(cur + 1);
                p[cur + 1] = cur;
            }
            if(cur * 2 <= 100000 && visit[cur * 2] == 0)
            {
                visit[cur * 2] = 1;
                q.push(cur * 2);
                p[cur * 2] = cur;
            }
        }
        if(findFlag) break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    bfs(n, k);

    vector<int> route;
    int ind = k;
    route.push_back(ind);
    while(ind != n)
    {
        route.push_back(p[ind]);
        ind = p[ind];
    }
    cout << ret << "\n";
    for(int i = route.size() - 1; i >= 0; i--)
        cout << route[i] << " ";
    return 0;
}