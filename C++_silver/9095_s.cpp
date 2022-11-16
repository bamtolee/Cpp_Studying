#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, *a;

    cin >> t;
    while(t--)
    {
        cin >> n;
        a = new int[n + 1];
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        for(int i = 4; i <= n; i++) a[i] = a[i - 3] + a[i - 2] + a[i - 1];
        cout << a[n] << "\n";
        delete[] a;
    }
    return 0;
}