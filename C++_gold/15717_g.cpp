#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int n;

    cin >> n;
    n--;
    long long int i = 1;
    long long int k = 2;
    while(n != 0)
    {
        if(n % 2 == 1)
        {
            i *= k;
            i %= 1000000007;
        }
        k *= k;
        k %= 1000000007;
        n /= 2;
    }
    cout << i;
    return 0;
}