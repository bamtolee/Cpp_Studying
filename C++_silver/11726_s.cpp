#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *a;

    cin >> n;
    a = new int[n + 1];
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i <= n; i++) a[i] = (a[i - 2] + a[i - 1]) % 10007;
    cout << a[n];
    delete[] a;
    return 0;
}