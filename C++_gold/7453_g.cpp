#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int a[4001];
int b[4001];
int c[4001];
int d[4001];
vector<int> sumAB;
vector<int> sumCD;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tmp1 = a[i] + b[j];
            int tmp2 = c[i] + d[j];
            sumAB.push_back(tmp1);
            sumCD.push_back(tmp2);
        }
    }

    ll ret = 0;
    sort(sumCD.begin(), sumCD.end());
    for(int i = 0; i < (int)sumAB.size(); i++)
    {
        ll left = lower_bound(sumCD.begin(), sumCD.end(), -sumAB[i]) - sumCD.begin();
        ll right = upper_bound(sumCD.begin(), sumCD.end(), -sumAB[i]) - sumCD.begin();
        ret += right - left;
    }
    cout << ret;
    return 0;
}