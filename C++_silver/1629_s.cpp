#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int a, b, c;
    long long int i = 1;
    cin >> a >> b >> c;

    while(b)
    {
        if(b % 2 == 1) 
        {
            i *= a;
            i %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    cout << i;
    return 0;
}