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
    a[1][0] = 0;
    for(int i = 1; i <= 9; i++) a[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i] = new long long int[10];
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0) a[i][j] = (a[i - 1][1]) % 1000000000;
            else if(j == 9) a[i][j] = (a[i - 1][8]) % 1000000000;
            else a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % 1000000000;
        }
    }
    for(int i = 0; i <= 9; i++)
    {
        ret += a[n][i];
        ret %= 1000000000;
    }
    cout << ret;
    for(int i = 1; i <= n; i++) delete[] a[i];
    delete[] a;
    return 0;
}