#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, *nol, tmpMax = 0;
    int m;
    cin >> n >> m;
    nol = new long long int[m];
    for(int i = 0; i < m; i++)
    {
        cin >> nol[i];
        if(tmpMax < nol[i]) tmpMax = nol[i];
    }
    
    if(n <= m) cout << n;
    else
    {
        long long int left = 1;
        long long int right = (n - m) * tmpMax;
        while(left <= right)
        {
            long long int mid = (left + right) / 2LL;
            long long int sum = 0;

            for(int i = 0; i < m; i++)
            {
                sum += mid / nol[i];
                if(sum > n - m) break;
            }
            if(sum < n - m) left = mid + 1LL;
            else right = mid - 1LL;
        }
        long long int minTime = right + 1LL;
        long long int lastCheck = m;
        for(int i = 0; i < m; i++)
            lastCheck += right / nol[i];
        for(int i = 0; i < m; i++)
        {
            if(minTime % nol[i] == 0) lastCheck++;
            if(lastCheck == n)
            {
                cout << i + 1;
                break;
            }
        }
    }
    return 0;
}