#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long int, long long int> co;

int ccw(co a1, co a2, co b)
{
    long long int f = a1.first * a2.second + a2.first * b.second + b.first * a1.second;
    long long int s = a2.first * a1.second + b.first * a2.second + a1.first * b.second;
    if(f == s) return 0;
    else if(f < s) return -1;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    co fir[2];
    co sec[2];
    for(int i = 0; i < 2; i++)
    {
        long long int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        fir[i].first = tmp1;
        fir[i].second = tmp2;
    }
    for(int i = 0; i < 2; i++)
    {
        long long int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        sec[i].first = tmp1;
        sec[i].second = tmp2;
    }
    if(ccw(fir[0], fir[1], sec[0]) * ccw(fir[0], fir[1], sec[1]) < 0
        && ccw(sec[0], sec[1], fir[0]) * ccw(sec[0], sec[1], fir[1]) < 0)
        cout << 1;
    else cout << 0;
    return 0;
}