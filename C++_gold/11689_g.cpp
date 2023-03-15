#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

ll powpow(ll n, ll k)
{
    ll i = 1;
    while(k != 0)
    {
        if(k % 2 == 1) i *= n;
        n *= n;
        k /= 2;
    }
    return i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k = 2, ret = 1;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    ll check = (ll)sqrt(n);
    int count = 0;
    while(k <= check && n != 1)
    {
        if(n % k == 0)
        {
            count++;
            n /= k;
        }
        else
        {
            if(count > 0)
            {
                ret *= (powpow(k, count) - powpow(k, count - 1));
                count = 0;
            }
            k++;
        }
    }
    if(n == 1 && count > 0)
        ret *= (powpow(k, count) - powpow(k, count - 1));
    if(n > 1)
        ret *= n - 1;
    cout << ret;
    return 0;
}