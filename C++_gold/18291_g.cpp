#include <iostream>
using namespace std;

int main()
{
    int t;
    long long int  div = 1000000007;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int n;
        long long int a = 1;
        long long int mul = 2;
        
        cin >> n;
        if(n == 1 || n == 2)
        {
            cout << a << "\n";
            continue;
        }
        else
        {
            n -= 2;
            while(n)
            {
                if(n % 2 == 1)
                {
                    a *= mul;
                    a %= div;
                }
                mul *= mul;
                mul %= div;
                n /= 2;
            }
        }
        cout << a << "\n";
    }
    return 0;
}