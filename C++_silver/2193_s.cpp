#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long int a[91][2] = {0};

    cin >> n;
    a[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i][0] = a[i - 1][1] + a[i - 1][0];
        a[i][1] = a[i - 1][0];
    }
    cout << a[n][0] + a[n][1];
    return 0;
}