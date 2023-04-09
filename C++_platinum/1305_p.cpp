#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, *p;
    string s;
    cin >> l >> s;

    p = new int[l + 1];
    p[0] = 0;
    for(int i = 1, j = 0; i < l; i++)
    {
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) p[i] = ++j;
        else p[i] = 0;
    }
    cout << l - p[l - 1];
    return 0;
}