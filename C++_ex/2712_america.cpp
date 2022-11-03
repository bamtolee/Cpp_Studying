#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        float num, ret;
        string unit, ret_u;

        cin >> num;
        cin >> unit;
        if (unit.compare("kg") == 0)
        {
            ret = num * 2.2046;
            ret_u = "lb";
        }
        else if (unit.compare("lb") == 0)
        {
            ret = num * 0.4536;
            ret_u = "kg";
        }
        else if (unit.compare("l") == 0)
        {
            ret = num * 0.2642;
            ret_u = "g";
        }
        else if (unit.compare("g") == 0)
        {
            ret = num * 3.7854;
            ret_u = "l";
        }
        cout << fixed;
        cout.precision(4);
        cout << ret << " " << ret_u << "\n";
    }
    return 0;
}