#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, tmp, ret = 0;
    stack<int> s;

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        if(tmp == 0)
            s.pop();
        else
            s.push(tmp);
    }
    while(!s.empty())
    {
        ret += s.top();
        s.pop();
    }
    cout << ret;
    return 0;
}