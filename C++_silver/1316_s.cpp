#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0, i;
    int alpha[26];
    string str;

    cin >> n;
    while(n--)
    {
        cin >> str;
        for(i = 0; i < 26; i++) alpha[i] = 0;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] == str[i + 1]) continue;
            alpha[str[i] - 'a']++;
        }
        for(i = 0; i < 26; i++) if(alpha[i] > 1) break;
        if (i == 26) ret++;
    }
    cout << ret;
    return 0;
}