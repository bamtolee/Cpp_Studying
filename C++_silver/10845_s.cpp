#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int cmd;
    queue<int> q;

    cin >> cmd;
    while(cmd--)
    {
        string tmp;
        int num;

        cin >> tmp;
        if(tmp == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if(tmp == "pop")
        {
            if(q.size() == 0) cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(tmp == "size") cout << q.size() << "\n";
        else if(tmp == "empty") cout << q.empty() << "\n";
        else if(tmp == "front")
        {
            if(q.size() == 0) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if(tmp == "back")
        {
            if(q.size() == 0) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}