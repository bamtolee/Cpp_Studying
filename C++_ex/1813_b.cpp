#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, nonli[51] = {0};
    int ret = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;

        cin >> tmp;
        nonli[tmp]++;
    }

    for(int i = 1; i < 51; i++)
    {
        if(nonli[i] == i)
            ret = i;
    }
    if(ret == 0  && nonli[0] > 0) ret = -1;
    cout << ret;
    return 0;
}