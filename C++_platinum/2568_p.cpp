#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> line;
vector<line> input;
vector<int> lis;
vector<int> lisIndex;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        input.push_back({tmp1, tmp2});
    }

    sort(input.begin(), input.end());
    int start = 0, maxInd = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            lis.push_back(input[i].second);
            lisIndex.push_back(maxInd);
        }
        else
        {
            int cur = input[i].second;
            if(cur > lis.back())
            {
                lis.push_back(cur);
                maxInd++;
                lisIndex.push_back(maxInd);
                start = i;
            }
            else
            {
                int tmp = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
                lis[tmp] = cur;
                lisIndex.push_back(tmp);
            }
        }
    }

    stack<int> s;
    s.push(start);
    for(int i = start; i >= 0; i--)
    {
        if(lisIndex[start] - 1 == lisIndex[i])
        {
            start = i;
            s.push(start);
            if(lisIndex[start] == 0) break;
        }
    }
    cout << n - s.size() << "\n";
    for(int i = 0; i < n; i++)
    {
        if(!s.empty() && i == s.top()) s.pop();
        else
            cout << input[i].first << "\n";
    }
    return 0;
}