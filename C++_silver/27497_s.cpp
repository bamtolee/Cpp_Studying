#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    deque<char> str;
    stack<int> prevCmd;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cmd;
        char input;

        cin >> cmd;
        if(cmd == 1)
        {
            cin >> input;
            str.push_back(input);
            prevCmd.push(cmd);
        }
        else if(cmd == 2)
        {
            cin >> input;
            str.push_front(input);
            prevCmd.push(cmd);
        }
        else
        {
            if(str.empty()) continue;
            int prev = prevCmd.top();
            prevCmd.pop();
            if(prev == 1) str.pop_back();
            else if(prev == 2) str.pop_front();
        }
    }
    if(str.empty()) cout << 0;
    else
    {
        while(!str.empty())
        {
            cout << str.front();
            str.pop_front();
        }
    }
    return 0;
}