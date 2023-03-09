#include <iostream>
using namespace std;

typedef long long int ll;
ll arr[5][5];
ll id[5][5];

void matrixMul(ll a[][5], ll b[][5], int n, int mod)
{
    ll c[5][5];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= 1000;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = c[i][j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int mod = 1000;
    ll b;
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(i == j) id[i][j] = 1;
            else id[i][j] = 0;
        }
    }
    
    while(b != 0)
    {
        if(b % 2LL == 1LL) matrixMul(id, arr, n, mod);
        matrixMul(arr, arr, n, mod);
        b /= 2;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << id[i][j] << " ";
        cout << "\n";
    }
    return 0;
}