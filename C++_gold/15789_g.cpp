#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> setInfor;
vector<setInfor> v(100001, {0, 0});
int p[100001];

bool compare(setInfor a, setInfor b)
{
    return a.first > b.first;
}

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(p[a] == a) return p[a];
    else return p[a] = findSet(p[a]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if(a != b)
    {
        if(a > b) p[a] = b;
        else p[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        makeSet(i);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unionSet(x, y);
    }
    
    int c, h, k;
    cin >> c >> h >> k;
    
    int check = findSet(h);
    int our = findSet(c);
    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        if(findSet(i) == our)
            ret++;
        else if(findSet(i) == check)
            continue;
        else
        {
            int tmp = findSet(i);
            v[tmp].second = tmp;
            v[tmp].first++;
        }
    }
    sort(v.begin(), v.end(), compare);
    int count = 0, i = 0;
    while(count < k)
    {
        if(i >= n || v[i].second == 0) break;
        ret += v[i].first;
        i++;
        count++;
    }
    cout << ret;
    return 0;
}