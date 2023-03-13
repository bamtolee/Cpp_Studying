#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++)
    {
        if(i == 0) dp[i] = 1;
        else
        {
            int tmpMax = 0;
            for(int j = 0; j < i; j++)
            {
                if(arr[i] > arr[j] && dp[j] > tmpMax)
                    tmpMax = dp[j];
            }
            dp[i] = tmpMax + 1;
        }
    }
    
    int maxIndex = 0, ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > ret)
        {
            ret = dp[i];
            maxIndex = i;
        }
    }
    cout << ret << "\n";
    stack<int> lis;
    lis.push(arr[maxIndex]);
    for(int i = maxIndex - 1; i >= 0; i--)
    {
        if(dp[maxIndex] - 1 == dp[i])
        {
            lis.push(arr[i]);
            maxIndex = i;
        }
    }
    while(!lis.empty())
    {
        cout << lis.top() << " ";
        lis.pop();
    }
    return 0;
}