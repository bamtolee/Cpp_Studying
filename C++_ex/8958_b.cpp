#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        int ret = 0;
        int count = 0;
        
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == 'O')
            {
                count++;
                ret += count;
            }
            else count = 0;
        }
        cout << ret << "\n";
    }
    return 0;
}