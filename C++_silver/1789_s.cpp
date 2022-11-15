#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int s, i = 1;
    int ret = 0;

    cin >> s;
    while(s > 0)
    {
        s -= i;
        i++;
        if(s >= 0) ret++;
    }
    cout << ret;
    return 0;
}