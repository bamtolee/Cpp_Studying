#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, maxInd = 0, start;
    vector<int> lis;
    vector<int> index;
    vector<int> in;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        in.push_back(cur);
        if(i == 0)
        {
            lis.push_back(cur);
            index.push_back(maxInd);
            start = 0;
        }
        else
        {
            if(cur > lis.back())
            {
                maxInd++;
                lis.push_back(cur);
                index.push_back(maxInd);
                start = i;
            }
            else
            {
                int tmp = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
                lis[tmp] = cur;
                index.push_back(tmp);
            }
        }
    }

    cout << lis.size() << "\n";
    stack<int> realLIS;
    realLIS.push(in[start]);
    for(int i = start; i >= 0; i--)
    {
        if(index[start] - 1 == index[i])
        {
            start = i;
            realLIS.push(in[i]);
            if(index[i] == 0) break;
        }
    }
    while(!realLIS.empty())
    {
        cout << realLIS.top() << " ";
        realLIS.pop();
    }
    return 0;
}