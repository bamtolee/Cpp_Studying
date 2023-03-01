#include <iostream>
using namespace std;

int *p;

void makeSet(int x)
{
    p[x] = x;
}

int findSet(int x)
{
    if(p[x] == x) return x;
    else return p[x] = findSet(p[x]);
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
    p = new int[n + 1];

    for(int i = 0; i <= n; i++)
        makeSet(i);
    for(int i = 0; i < m; i++)
    {
        int cmd, a, b;
        
        cin >> cmd >> a >> b;
        if(cmd == 0)
            unionSet(a, b);
        else if(cmd == 1)
        {
            int tmp1 = findSet(a);
            int tmp2 = findSet(b);
            if(tmp1 != tmp2)
                cout << "no\n";
            else
                cout << "yes\n";
        }
    }
    return 0;
}