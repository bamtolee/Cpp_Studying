#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int ret = 0;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'z' && str[i + 1] == '=') i++;
        else if(str[i] == 's' && str[i + 1] == '=') i++;
        else if(str[i] == 'n' && str[i + 1] == 'j') i++;
        else if(str[i] == 'l' && str[i + 1] == 'j') i++;
        else if(str[i] == 'd')
        {
            if(str[i + 1] == '-') i++;
            else if(str[i + 1] == 'z' && str[i + 2] == '=') i += 2;
        }
        else if(str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')) i++;
        ret++;
    }
    cout << ret;
    return 0;
}