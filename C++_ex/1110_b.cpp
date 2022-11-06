#include <iostream>
using namespace std;

int main()
{
    int n, mid, count = 0;

    cin >> n;
    mid = ((n % 10) * 10) + ((n / 10 + n % 10) % 10);
    count++;
    while (mid != n)
    {
        mid = ((mid % 10) * 10) + ((mid / 10 + mid % 10) % 10);
        count++;
    }
    cout << count;
    return 0;
}