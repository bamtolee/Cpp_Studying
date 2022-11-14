#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, p, price, max_pr;
    string str, ret;

    cin >> n;
    while(n--)
    {
        cin >> p;
        max_pr = 0;
        while(p--)
        {
            cin >> price >> str;
            if (price > max_pr)
            {
                max_pr = price;
                ret = str;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}