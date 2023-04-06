#include <iostream>
using namespace std;

typedef long long int ll;
ll factorial[2001];

ll dqPow(ll a, ll b, ll m)
{
    ll i = 1;
    while(b > 0)
    {
        if((b & 1) == 1)
        {
            i *= a;
            i %= m;
        }
        a *= a;
        a %= m;
        b = b >> 1;
    }
    return i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, m;
    cin >> n >> k >> m;
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= m; i++)
        factorial[i] = factorial[i - 1] * (ll)i % m;

    ll ret = 1;
    while(n > 0 || k > 0)
    {
        ll a = n % m;
        ll b = k % m;
        if(a < b)
        {
            ret = 0;
            break;
        }
        ll numer = factorial[(int)a];
        ll denom = dqPow(factorial[(int)b], m - 2, m);
        denom *= dqPow(factorial[(int)(a - b)], m - 2, m);
        denom %= m;
        ret *= numer;
        ret %= m;
        ret *= denom;
        ret %= m;
        n /= m;
        k /= m;
    }
    cout << ret;
    return 0;
}