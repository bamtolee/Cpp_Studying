#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int a, b, r;
    long long int maxx, minn;

    cin >> a >> b;
    maxx = max(a, b);
    minn = min(a, b);
    while(minn != 0)
    {
        r = maxx % minn;
        maxx = minn;
        minn = r;
    }
    while(maxx--) cout << "1";
    return 0;
}