#include <iostream>
using namespace std;

int main()
{
    int t, x, ret, c_num;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ret = 0;
        c_num = 1;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            c_num += (j + 1);
            ret = ret + (j * c_num);
        }
        cout << ret << '\n';
    }
    return 0;
}