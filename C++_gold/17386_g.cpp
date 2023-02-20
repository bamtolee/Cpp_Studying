#include <iostream>
#include <vector>
using namespace std;

int ccw(long long int x1, long long int x2, long long int x3, long long int y1, long long int y2, long long int y3)
{
    if(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3 > 0) return 1;
    else if(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3 == 0) return 0;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<long long int> co;
    for(int i = 0; i < 8; i++)
    {
        long long int tmp;

        cin >> tmp;
        co.push_back(tmp);
    }
    if(ccw(co[0], co[2], co[4], co[1], co[3], co[5])
        * ccw(co[0], co[2], co[6], co[1], co[3], co[7]) < 0
        &&
        ccw(co[4], co[6], co[0], co[5], co[7], co[1])
        * ccw(co[4], co[6], co[2], co[5], co[7], co[3]) < 0)
        cout << 1;
    else cout << 0;
    return 0;
}