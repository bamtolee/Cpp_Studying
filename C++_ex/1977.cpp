#include <iostream>
using namespace std;

int main()
{
    int m, n, min_flag;
    int ret_sum, ret_min;

    cin >> m >> n;
    min_flag = 0;
    ret_sum = 0;
    for (int i = m; i <= n; i++)
    {
        int j = 1;
        while (j * j <= i)
        {
            if (j * j == i)
            {
                ret_sum += i;
                if (min_flag == 0)
                {
                    min_flag = 1;
                    ret_min = i;
                }
                break;
            }
            j++;
        }
    }
    if (ret_sum == 0)
        cout << "-1";
    else
        cout << ret_sum << "\n" << ret_min;
    return 0;
}