#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int *a;

    cin >> n;
    a = new int[n + 1];
    a[1] = 1;
    a[2] = 3;
    for(int i = 3; i <= n; i++) a[i] = (a[i - 1] + 2 * a[i - 2]) % 10007;
    cout << a[n];
    return 0;
}