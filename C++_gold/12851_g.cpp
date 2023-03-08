#include <iostream>
#include <queue>
using namespace std;

int ret = 0;
int methods = 0;
int visit[100001];
bool findFlag = false;
queue<int> q;

void kCheck(int t, int k)
{
    if(t == k)
    {
        findFlag = true;
        methods++;
    }
    else
        q.push(t);
}

void bfs(int n, int k)
{
    fill(visit, visit + 100001, 0);
    q.push(n);
    
    while(!q.empty())
    {
        int qSize = q.size();
        ret++;
        for(int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            if(cur == k)
            {
                methods++;
                ret--;
                findFlag = true;
                break;
            }
            q.pop();
            visit[cur] = 1;

            if(cur - 1 >= 0 && visit[cur - 1] == 0)
                kCheck(cur - 1, k);
            if(cur + 1 <= 100000 && visit[cur + 1] == 0)
                kCheck(cur + 1, k);
            if(cur * 2 <= 100000 && visit[cur * 2] == 0)
                kCheck(cur * 2, k);
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
    cout << ret << "\n" << methods;
    return 0;
}