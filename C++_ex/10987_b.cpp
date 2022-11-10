#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    int ret = 0;
    vector<char> col = {'a', 'e', 'i', 'o', 'u'};

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        for(auto j : col)
        {
            if(str[i] == j)
            {
                ret++;
                break;
            }
        }
    }
    cout << ret;
    return 0;
}