#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n;
    stack<int> s;

    cin >> n;
    while(n--)
    {
        string cmd;
        int num;

        cin >> cmd;
        if(cmd == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop")
        {
            if(s.empty()) cout << "-1\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(cmd == "top")
        {
            if(s.empty()) cout << "-1\n";
            else cout << s.top() << "\n";
        }
        else if(cmd == "size") cout << s.size() << "\n";
        else if(cmd == "empty") cout << s.empty() << "\n";
    }
    return 0;
}