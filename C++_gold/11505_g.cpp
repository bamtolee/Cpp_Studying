#include <iostream>
using namespace std;

typedef long long int ll;
ll mod = 1000000007;
ll arr[1000001];
ll segTree[4000002];

ll init(int start, int end, int cur)
{
    if(start == end) return segTree[cur] = arr[start];
    int mid = (start + end) / 2;
    return segTree[cur] = init(start, mid, cur * 2)
        * init(mid + 1, end, cur * 2 + 1) % mod;
}

ll modify(int start, int end, int cur, int index, ll renew)
{
    if(index < start || index > end) return segTree[cur];
    else if(start == end)
    {
        segTree[cur] = renew;
        return segTree[cur];
    }
    
    int mid = (start + end) / 2;
    return segTree[cur] = modify(start, mid, cur * 2, index, renew)
        * modify(mid + 1, end, cur * 2 + 1, index, renew) % mod;
}

ll mul(int start, int end, int cur, int left, int right)
{
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return segTree[cur];
    
    int mid = (start + end) / 2;
    return mul(start, mid, cur * 2, left, right)
        * mul(mid + 1, end, cur * 2 + 1, left, right) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    init(0, n - 1, 1);
    
    for(int i = 0; i < m + k; i++)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            int b;
            ll c;
            cin >> b >> c;
            arr[b - 1] = c;
            modify(0, n - 1, 1, b - 1, c);
        }
        else if(a == 2)
        {
            int b, c;
            cin >> b >> c;
            cout << mul(0, n - 1, 1, b - 1, c - 1) << "\n";
        }
    }
    return 0;
}