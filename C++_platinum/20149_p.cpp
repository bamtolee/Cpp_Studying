#include <iostream>
using namespace std;

typedef long long int ll;
double interX;
double interY;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a = x1 * y2 + x2 * y3 + x3 * y1;
    ll b = x2 * y1 + x3 * y2 + x1 * y3;
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

void inter(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    if(x2 != x1 && x4 != x3)
    {
        double a = (double)(y2 - y1) / (double)(x2 - x1);
        double c = (double)(y4 - y3) / (double)(x4 - x3);
        double b = (double)(((x1 * -1) * y2) + (x2 * y1)) / (double)(x2 - x1);
        double d = (double)(((x3 * -1) * y4) + (x4 * y3)) / (double)(x4 - x3);

        if(a != c)
        {
            interX = (d - b) / (a - c);
            interY = ((a * d) - (c * b)) / (a - c);
            cout << interX << " " << interY;
        }
        else
        {
            ll minL1 = x1 > x2 ? x2 : x1;
            ll maxL1 = x1 < x2 ? x2 : x1;
            ll minL2 = x3 > x4 ? x4 : x3;
            ll maxL2 = x3 < x4 ? x4 : x3;
            if(minL1 == maxL2)
            {
                if(maxL2 == x3)
                    cout << x3 << " " << y3;
                else if(maxL2 == x4)
                    cout << x4 << " " << y4;
            }
            else if(minL2 == maxL1)
            {
                if(minL2 == x3)
                    cout << x3 << " " << y3;
                else if(minL2 == x4)
                    cout << x4 << " " << y4;
            }
        }
    }
    else if(x2 == x1 && x4 != x3)
    {
        double c = (double)(y4 - y3) / (double)(x4 - x3);
        double d = (double)(((x3 * -1) * y4) + (x4 * y3)) / (double)(x4 - x3);
        interX = x1;
        interY = (double)(c * x1) + d;
        cout << interX << " " << interY;
    }
    else if(x4 == x3 && x2 != x1)
    {
        double a = (double)(y2 - y1) / (double)(x2 - x1);
        double b = (double)(((x1 * -1) * y2) + (x2 * y1)) / (double)(x2 - x1);
        interX = x3;
        interY = (double)(a * x3) + b;
        cout << interX << " " << interY;
    }
    else if(x4 == x3 && x2 == x1)
    {
        ll minL1 = y1 > y2 ? y2 : y1;
        ll maxL1 = y1 < y2 ? y2 : y1;
        ll minL2 = y3 > y4 ? y4 : y3;
        ll maxL2 = y3 < y4 ? y4 : y3;
        if(minL1 == maxL2)
        {
            if(maxL2 == y3)
                cout << x3 << " " << y3;
            else if(maxL2 == y4)
                cout << x4 << " " << y4;
        }
        else if(minL2 == maxL1)
        {
            if(minL2 == y3)
                cout << x3 << " " << y3;
            else if(minL2 == y4)
                cout << x4 << " " << y4;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed;
    cout.precision(9);
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) == 0
    && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) == 0)
    {
        ll min1 = x1 > x2 ? x2 : x1;
        ll max1 = x1 < x2 ? x2 : x1;
        ll max2 = x3 > x4 ? x3 : x4;
        ll min2 = x4 < x3 ? x4 : x3;
        if(x1 == x2 && x2 == x3 && x3 == x4)
        {
            ll miny1 = y1 > y2 ? y2 : y1;
            ll maxy1 = y1 < y2 ? y2 : y1;
            ll maxy2 = y3 > y4 ? y3 : y4;
            ll miny2 = y4 < y3 ? y4 : y3;
            if(miny1 >= miny2 && maxy2 >= miny1)
            {
                cout << 1 << "\n";
                inter(x1, y1, x2 ,y2, x3, y3, x4, y4);
            }
            else if(miny2 >= miny1 && maxy1 >= miny2)
            {
                cout << 1 << "\n";
                inter(x1, y1, x2 ,y2, x3, y3, x4, y4);
            }
            else cout << 0;
        }
        else if(min1 >= min2 && max2 >= min1)
        {
            cout << 1 << "\n";
            inter(x1, y1, x2 ,y2, x3, y3, x4, y4);
        }
        else if(min2 >= min1 && max1 >= min2)
        {
            cout << 1 << "\n";
            inter(x1, y1, x2 ,y2, x3, y3, x4, y4);
        }
        else cout << 0;
    }
    else if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0
        && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) <= 0)
    {
        cout << 1 << "\n";
        inter(x1, y1, x2 ,y2, x3, y3, x4, y4);
    }
    else cout << 0;
    return 0;
}