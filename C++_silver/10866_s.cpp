#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    int cmd;
    deque<int> d;

    cin >> cmd;
    while(cmd--)
    {
        string tmp;
        int num;

        cin >> tmp;
        if(tmp == "push_front")
        {
            cin >> num;
            d.push_front(num);
        }
        else if(tmp == "push_back")
        {
            cin >> num;
            d.push_back(num);
        }
        else if(tmp == "pop_front")
        {
            if(d.size() == 0) cout << "-1\n";
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if(tmp == "pop_back")
        {
            if(d.size() == 0) cout << "-1\n";
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if(tmp == "size") cout << d.size() << "\n";
        else if(tmp == "empty") cout << d.empty() << "\n";
        else if(tmp == "front")
        {
            if(d.size() == 0) cout << "-1\n";
            else cout << d.front() << "\n";
        }
        else if(tmp == "back")
        {
            if(d.size() == 0) cout << "-1\n";
            else cout << d.back() << "\n";
        }
    }
    return 0;
}