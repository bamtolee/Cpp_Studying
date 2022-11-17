#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long int **a, ret = 0;

    cin >> n;
    a = new long long int*[n + 1];
    a[1] = new long long int[10];
    for(int i = 0; i < 10; i++)
        a[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i] = new long long int[10];
        for(int j = 0; j < 10; j++)
        {
            a[i][j] = 0;
            for(int k = 0; k <= j; k++) a[i][j] += (a[i - 1][k]) % 10007;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        ret += a[n][i];
        ret %= 10007;
    }
    cout << ret;
    for(int i = 1; i <= n; i++) delete[] a[i];
    delete[] a;
    return 0;
}