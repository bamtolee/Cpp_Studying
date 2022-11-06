#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<int> v(26);
    int tmp, max_cnt = 0;
    char ret = '0';

    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        tmp = s[i] - 'A';
        if(s[i] >= 'a')
            tmp = s[i] - 'a';
        v[tmp]++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(v[i] > max_cnt)
        {
            ret = 'A' + i;
            max_cnt = v[i];
        }
        else if(v[i] == max_cnt)
            ret = '?';
    }
    cout << ret;
    return 0;
}