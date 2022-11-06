#include <iostream>
using namespace std;

int main()
{
    int n, tmp;
    int max = 2;
    int min = 1000000;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < min)
            min = tmp;
        if (tmp > max)
            max = tmp;
    }
    cout << max * min;
    return 0;
}