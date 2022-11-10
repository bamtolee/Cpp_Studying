#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++)
    {
        string tmp;
        int a, b, ret;

        getline(cin, tmp);
        a = tmp[0] - '0';
        b = tmp[2] - '0';
        ret = a + b;
        cout << ret << "\n";
    }
    return 0;
}