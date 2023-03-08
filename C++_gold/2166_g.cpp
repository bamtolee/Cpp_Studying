#include <iostream>
#include <vector>
using namespace std;

typedef pair<double, double> co;
vector<co> v;

double ccw(co a1, co a2, co a3)
{
    double f = a1.first * a2.second + a2.first * a3.second + a3.first * a1.second;
    double s = a2.first * a1.second + a3.first * a2.second + a1.first * a3.second;
    return f - s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);

    int n;
    double ret = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back({tmp1, tmp2});
    }

    for(int i = 0; i < n - 2; i++)
        ret += 0.5 * ccw(v[0], v[i + 1], v[i + 2]);
    if(ret > 0)
        cout << ret;
    else
        cout << -1.0 * ret;
    return 0;
}