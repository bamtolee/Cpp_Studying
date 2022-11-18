#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] > 'm') str[i] = 'a' + (str[i] - 'n');
            else str[i] += 13;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 13;
            if(str[i] > 'Z') str[i] = 'A' + (str[i] - 'Z' - 1);
        }
    }
    cout << str;
    return 0;
}