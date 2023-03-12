#include <iostream>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll k, c;
        cin >> k >> c;

        if(gcd(k, c) != 1)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else
        {
            ll s1 = 1;
            ll s2 = 0;
            ll t1 = 0;
            ll t2 = 1;
            ll a = k;
            ll b = c;

            while(b != 0)
            {
                ll q = a / b;
                ll r = a % b;
                ll tmp;

                a = b;
                b = r;
                tmp = s1;
                s1 = s2;
                s2 = tmp - q * s2;
                tmp = t1;
                t1 = t2;
                t2 = tmp - q * t2;
            }
            //s1은 음수, t1은 양수여야 함
            while(s1 >= 0 || t1 <= 0)
            {
                s1 -= c; t1 += k;
                if(t1 > 1000000000) break;
            }
            if(t1 <= 1000000000) cout << t1 << "\n";
            else cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}