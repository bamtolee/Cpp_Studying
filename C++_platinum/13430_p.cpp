#include <iostream>
using namespace std;

typedef long long int ll;
ll mod = 1000000007;
ll factorial[52];

ll dqPow(ll a, ll b)
{
    ll i = 1;
    while(b > 0)
    {
        if((b & 1) != 0)
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

    ll k, n, ret = 1;
    cin >> k >> n;
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 51; i++)
        factorial[i] = factorial[i - 1] * i % mod;
    
    ll numer = 1;
    for(ll i = n + k; i >= n; i--)
    {
        numer *= i;
        numer %= mod;
    }
    ll denom = dqPow(factorial[(int)(k + 1)], mod - 2);
    ret = numer * denom % mod;
    cout << ret;
    return 0;
}