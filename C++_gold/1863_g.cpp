#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0;
    stack<int> skyline;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;
        if(skyline.empty()) skyline.push(y);
        else if(skyline.top() < y) skyline.push(y);
        else if(skyline.top() > y)
        {
            while(!skyline.empty())
            {
                int tmp = skyline.top();
                if(tmp > y)
                {
                    skyline.pop();
                    ret++;
                }
                else if(tmp <= y) break;
            }
            if(skyline.empty() || skyline.top() != y) skyline.push(y);
        }
    }
    if(!skyline.empty())
    {
        while(!skyline.empty())
        {
            if(skyline.top() != 0) ret++;
            skyline.pop();
        }
    }
    cout << ret;
    return 0;
}