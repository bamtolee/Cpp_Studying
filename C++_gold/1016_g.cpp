#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
int check[1100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll mn, mx;
    int ret = 0;
    cin >> mn >> mx;

    int size = (mx - mn) + 1;
    for(int i = 0; i < size; i++)
        check[i] = 1;

    for(ll i = 2; i <= sqrt(mx); i++)
    {
        ll k = (i * i) - (mn % (i * i));
        if(mn % (i * i) == 0) k = 0;
        for(; k < size; k += (i * i))
            check[(int)k] = 0;
    }

    for(int i = 0; i < size; i++)
        ret += check[i];
    cout << ret;
    return 0;
}