#include <iostream>
using namespace std;

int main()
{
    int n, x = 0, y = 0, ret;

    cin >> n;
    while(n % 5 != 0 && n > 0)
    {
        n -= 3;
        x++;
    }
    if(n >= 0)
    {
        y += n / 5;
        ret = x + y;
    }
    else if(n < 0) ret = -1;
    cout << ret;
    return 0;
}