#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, s = 0;
    cin >> m;
    while(m--)
    {
        string cmd;
        cin >> cmd;

        if(cmd.compare("add") == 0)
        {
            int x;
            cin >> x;
            s |= (1 << x);
        }
        else if(cmd.compare("remove") == 0)
        {
            int x;
            cin >> x;
            if((s & (1 << x)) != 0)
                s ^= (1 << x);
        }
        else if(cmd.compare("check") == 0)
        {
            int x;
            cin >> x;
            if((s & (1 << x)) != 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(cmd.compare("toggle") == 0)
        {
            int x;
            cin >> x;
            s ^= (1 << x);
        }
        else if(cmd.compare("all") == 0)
        {
            for(int i = 1; i <= 20; i++)
                s |= (1 << i);
        }
        else if(cmd.compare("empty") == 0)
        {
            s &= 0;
        }
    }
    return 0;
}