#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i = 2;

    cin >> n;
    if(n == 1) return 0;
    while(n > 1)
    {
        while(n % i == 0)
        {
            cout << i << "\n";
            n /= i;
        }
        i++;
    }
    return 0;
}