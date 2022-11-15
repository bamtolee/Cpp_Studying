#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, a, b, minn, maxx, r;

    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        minn = min(a, b);
        maxx = max(a, b);
        while(minn != 0)
        {
            r = maxx % minn;
            maxx = minn;
            minn = r;
        }
        cout << a * b / maxx << "\n";
    }
}