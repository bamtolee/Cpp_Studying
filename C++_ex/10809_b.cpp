#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char a = 'a';

    cin >> str;
    for(int i = 0; i < 26; i++)
    {
        int j = 0;
        for(; j < str.length(); j++)
            if(str[j] == a) break;
        if(j == str.length()) cout << "-1 ";
        else cout << j << " ";
        a++;
    }
    return 0;
}