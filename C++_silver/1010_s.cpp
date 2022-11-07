#include <iostream>
using namespace std;

int main()
{
    int t, n, m;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int ret = 1;
        int x = 1;

        cin >> n >> m;
        for(int j = m; j > m - n; j--)
        {
            ret *= j;
            ret /= x;
            x++;
        }
        cout << ret << "\n";
    }
    return 0;
}