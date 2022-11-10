#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long int>> llmatrix;

llmatrix llmmul_and_mod(llmatrix a, llmatrix b, long long int div)
{
    llmatrix ret(2, vector<long long int>(2));
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++) ret[i][j] += a[i][k] * b[k][j];
            ret[i][j] %= div;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int n;
    long long int div = 1000000007;
    llmatrix i = {{1, 0}, {0, 1}};
    llmatrix m = {{1, 1}, {1, 0}};

    cin >> n;
    while(n)
    {
        if(n % 2 == 1) i = llmmul_and_mod(i, m, div);
        m = llmmul_and_mod(m, m, div);
        n /= 2;
    }
    cout << i[0][1];
    return 0;
}