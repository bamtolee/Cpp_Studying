#include <iostream>
using namespace std;

int p[500000] = {0};

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(p[a] == a) return a;
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
    for(int i = 0; i < n; i++)
        makeSet(i);

    int ret = 0;
    bool cycleFlag = false;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(cycleFlag) continue;
        if(findSet(a) != findSet(b))
            unionSet(a, b);
        else
        {
            cycleFlag = true;
            ret = i;
        }
    }
    cout << ret;
    return 0;
}