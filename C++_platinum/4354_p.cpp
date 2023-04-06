#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true)
    {
        string s;
        cin >> s;
        if(s.compare(".") == 0) break;
        int *p;
        int is = (int)s.size();
        p = new int[is + 1];
        for(int i = 1, j = 0; i < is; i++)
        {
            while(j > 0 && s[i] != s[j]) j = p[j - 1];
            if(s[i] == s[j]) p[i] = ++j;
            else p[i] = 0;
        }

        int q = is / (is - p[is - 1]);
        int r = is % (is - p[is - 1]);
        if(r != 0) cout << 1 << "\n";
        else
            cout << q << "\n";
    }
    return 0;
}