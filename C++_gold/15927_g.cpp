#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int ret = -1;
    int left = 0, right = (int)s.size() - 1;
    while(left <= right)
    {
        if(s[left] != s[right])
        {
            ret = (int)s.size();
            break;
        }
        else
        {
            if(left != 0 && (s[left] != s[left - 1] || s[left] != s[right + 1]))
                ret = (int)s.size() - 1;
        }
        left++;
        right--;
    }
    cout << ret;
    return 0;
}