#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int ret = 0, pnum = 0;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            ret++;
            pnum++;
        }
        else if(i > 0 && str[i - 1] == '(' && str[i] == ')')
        {
            pnum--;
            ret--;
            ret += pnum;
        }
        else if(str[i] == ')') pnum--;
    }
    cout << ret;
    return 0;
}