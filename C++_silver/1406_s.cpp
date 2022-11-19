#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int cmd;
    list<char> l;
    char c;

    cin >> str >> cmd;
    for(auto i : str) l.push_back(i);
    list<char>::iterator iter = l.end();
    while(cmd--)
    {
        cin >> c;
        if(c == 'L')
        {
            if(iter == l.begin()) continue;
            iter--;
        }
        else if(c == 'D')
        {
            if(iter == l.end()) continue;
            iter++;
        }
        else if(c == 'B')
        {
            if(iter == l.begin()) continue;
            iter--;
            iter = l.erase(iter);
        }
        else if(c == 'P')
        {
            cin >> c;
            iter = l.insert(iter, c);
            iter++;
        }
    }
    for(auto i : l) cout << i;
    return 0;
}