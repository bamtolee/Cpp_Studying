#include <iostream>
using namespace std;

typedef unsigned long long int ull;
ull baseList[3] = {2, 7, 61};

ull dqPow(ull a, ull b, ull mod)
{
    ull i = 1;
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

bool millerRabin(ull target, ull base)
{
    if(base == target) return true;

    ull m = target - 1;
    int k = 1;
    while(m % 2 == 0)
    {
        m /= 2;
        if(m % 2 == 0)
        {
            k++;
            continue;
        }
        ull t = dqPow(base, m, target);
        if(t == 1 || t == target - 1) return true;
        for(int i = 1; i <= k - 1; i++)
        {
            t = t * t % target;
            if(t == 1) return false;
            else if(t == target - 1) return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0;
    cin >> n;
    while(n--)
    {
        ull area;
        cin >> area;
        for(int i = 0; i < 3; i++)
        {
            if(!millerRabin(2 * area + 1, baseList[i]))
                break;
            if(i == 2) ret++;
        }
    }
    cout << ret;
    return 0;
}