#include <iostream>
using namespace std;

typedef long long int ll;
ll a[1000001];
ll fenwick[1000001];

void modify(int n, int i, ll num)
{
    while(i <= n)
    {
        fenwick[i] += num;
        i += (i & (i * (-1)));
    }
}

ll sum(int n, int i)
{
    ll ret = 0;
    while(i > 0)
    {
        ret += fenwick[i];
        i -= (i & (i * (-1)));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int cmd;
        cin >> cmd;
        if(cmd == 1)
        {
            int ii, k;
            cin >> ii >> k;
            
            ll tmp = a[ii];
            a[ii] = k;
            modify(n, ii, k - tmp);
        }
        else if(cmd == 0)
        {
            int ii, j;
            cin >> ii >> j;
            if(ii > j)
            {
                int tmp = ii;
                ii = j;
                j = tmp;
            }
            cout << sum(n, j) - sum(n, ii - 1) << "\n";
        }
    }
    return 0;
}