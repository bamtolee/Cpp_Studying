#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, of_flag;
    long long int ret, x;

    for(int i = 0; i < 3; i++)
    {
        ret = 0;
        of_flag = 0;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            if (ret > 0 && x > 0 && x > LLONG_MAX - ret)
                    of_flag++;
            if (ret < 0 && x < 0 && x < LLONG_MIN - ret)
                    of_flag--;
            ret += x;
        }
        if (of_flag == 0)
        {
            if (ret > 0)
                cout << "+\n";
            else if (ret < 0)
                cout << "-\n";
            else if (ret == 0)
                cout << "0\n";
        }
        else if (of_flag < 0)
            cout << "-\n";
        else if (of_flag > 0)
            cout << "+\n";
    }
    return 0;
}