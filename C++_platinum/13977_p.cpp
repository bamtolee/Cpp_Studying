#include <iostream>
using namespace std;

typedef long long int ll;
ll mod = 1000000007;
ll factorial[4000001];

ll dqPow(ll a, ll b)
{
    ll i = 1;
    while(b > 0)
    {
        if((b & 1) == 1)
        {
            i *= a;
            i %= mod;
        }
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 4000000; i++)
        factorial[i] = factorial[i - 1] * (ll)i % mod;

    int m;
    cin >> m;
    while(m--)
    {
        ll n, k;
        cin >> n >> k;

        ll numer = factorial[n];
        ll denom = dqPow(factorial[k], mod - 2);
        denom *= dqPow(factorial[n - k], mod - 2);
        denom %= mod;
        ll ret = numer * denom % mod;
        cout << ret << "\n";
    }
    return 0;
}