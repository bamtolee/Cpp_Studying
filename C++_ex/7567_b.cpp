#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int ret = 0;

    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if(i == 0) ret += 10;
        else
        {
            if(str[i] != str[i - 1]) ret += 10;
            else if(str[i] == str[i - 1]) ret += 5;
        }
    }
    cout << ret;
    return 0;
}