#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;
ll a[1001] = {0};
ll b[1001] = {0};
ll aPSum[1001] = {0};
ll bPSum[1001] = {0};
vector<ll> possibleBP;
vector<ll> possibleAP;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, ret = 0;
    int n, m;
    cin >> t >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        aPSum[i] = aPSum[i - 1] + a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        bPSum[i] = bPSum[i - 1] + b[i];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            possibleAP.push_back(aPSum[i] - aPSum[j]);
    for(int i = 1; i <= m; i++)
        for(int j = 0; j < i; j++)
            possibleBP.push_back(bPSum[i] - bPSum[j]);
    sort(possibleAP.begin(), possibleAP.end());
    sort(possibleBP.begin(), possibleBP.end());

    for(int i = 0; i < (int)possibleAP.size(); i++)
    {
        ll sameStart = lower_bound(possibleBP.begin(), possibleBP.end(),
                                    t - possibleAP[i]) - possibleBP.begin();
        ll sameEnd = upper_bound(possibleBP.begin(), possibleBP.end(),
                                    t - possibleAP[i]) - possibleBP.begin();
        ret += sameEnd - sameStart;
    }
    cout << ret;
    return 0;
}