#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[10], sum = 0;
    int ret_avg, ret_mode;
    int temp, count, mx_count;

    for(int i = 0; i < 10; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ret_avg = sum / 10;
    sort(a, a + 10);
    temp = a[0];
    ret_mode = temp;
    count = 1;
    mx_count = 1;
    for(int i = 1; i < 10; i++)
    {
        if(a[i] != a[i - 1])
        {
            temp = a[i];
            count = 1;
        }
        else if(a[i] == a[i - 1])
        {
            count++;
            if(count > mx_count)
            {
                mx_count = count;
                ret_mode = a[i];
            }
        }
    }
    cout << ret_avg << "\n" << ret_mode;
    return 0;
}