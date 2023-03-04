#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n, a;
    long long int addInverse, mulInverse;

    cin >> n >> a;
    addInverse = n - a;
    long long int r1 = n;
    long long int r2 = a;
    long long int t1 = 0;
    long long int t2 = 1;
    while(r2 != 0)
    {
        long long int q = r1 / r2;
        long long int rem = r1 % r2;
        long long int tmp = t2;
        r1 = r2;
        r2 = rem;
        t2 = t1 - (t2 * q);
        t1 = tmp;
    }
    if(r1 != 1) mulInverse = -1;
    else
    {
        if(t1 < 0)
            mulInverse = n + t1;
        else
            mulInverse = t1;
    }
    cout << addInverse << " " << mulInverse;
    return 0;
}