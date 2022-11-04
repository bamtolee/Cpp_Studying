#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[5], avg;
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / 5;
    sort(a, a + 5);
    cout << avg << "\n" << a[2];
    return 0;
}