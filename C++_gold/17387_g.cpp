#include <iostream>
using namespace std;

typedef long long int ll;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = x2 * y1 + x3 * y2 + x1 * y3;
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0
        && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) < 0)
        cout << 1;
    else if((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)
        || (x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4))
        cout << 1;
    else if(ccw(x1, y1, x2, y2, x3, y3) == 0 && ccw(x1, y1, x2, y2, x4, y4) == 0
    && ccw(x1, y1, x3, y3, x4, y4) == 0 && ccw(x2, y2, x3, y3, x4, y4) == 0)
    {
        ll min1 = x1 > x2 ? x2 : x1;
        ll max1 = x1 < x2 ? x2 : x1;
        ll max2 = x3 > x4 ? x3 : x4;
        ll min2 = x4 < x3 ? x4 : x3;
        if(min1 > min2 && max2 > min1) cout << 1;
        else if(min2 > min1 && max1 > min2) cout << 1;
        else cout << 0;
    }
    else if(ccw(x1, y1, x2, y2, x3, y3) == 0 && ccw(x1, y1, x2, y2, x4, y4) != 0)
    {
        ll max1 = x1 > x2 ? x1 : x2;
        ll min1 = x1 < x2 ? x1 : x2;
        if(max1 >= x3 && min1 <= x3) cout << 1;
        else cout << 0;
    }
    else if(ccw(x1, y1, x2, y2, x3, y3) != 0 && ccw(x1, y1, x2, y2, x4, y4) == 0)
    {
        ll max1 = x1 > x2 ? x1 : x2;
        ll min1 = x1 < x2 ? x1 : x2;
        if(max1 >= x4 && min1 <= x4) cout << 1;
        else cout << 0;
    }
    else if(ccw(x1, y1, x3, y3, x4, y4) == 0 && ccw(x2, y2, x3, y3, x4, y4) != 0)
    {
        ll max1 = x3 > x4 ? x3 : x4;
        ll min1 = x3 < x4 ? x3 : x4;
        if(max1 >= x1 && min1 <= x1) cout << 1;
        else cout << 0;
    }
    else if(ccw(x1, y1, x3, y3, x4, y4) != 0 && ccw(x2, y2, x3, y3, x4, y4) == 0)
    {
        ll max1 = x3 > x4 ? x3 : x4;
        ll min1 = x3 < x4 ? x3 : x4;
        if(max1 >= x2 && min1 <= x2) cout << 1;
        else cout << 0;
    }
    else cout << 0;
    return 0;
}