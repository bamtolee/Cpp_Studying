#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> home;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    home.resize(n, 0);
    for(int i = 0; i < n; i++)
        cin >> home[i];
    
    int count = 0;
    if(n == 1) count = home[0];
    else
    {
        while(1)
        {
            sort(home.begin(), home.end());
            if(home[n - 1] == 0) break;
            count++;
            home[n - 1]--;
            if(home[n - 2] > 0)
                home[n - 2]--;
        }
    }
    if(count > 1440) cout << -1;
    else cout << count;
    return 0;
}