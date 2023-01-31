#include <iostream>
using namespace std;

int main()
{
    int t, n;
    long long int derangement[21] = {1, 0, };

    for(int i = 2; i <= 20; i++)
        derangement[i] = (long long int)(i - 1) * (derangement[i - 1] + derangement[i - 2]);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cout << derangement[n] << "\n";
    }
    return 0;
}