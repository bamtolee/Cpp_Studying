#include <iostream>
#include <vector>
using namespace std;

vector<int> cow(10, -1);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ret = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num, cur;

        cin >> num >> cur;
        if(cow[num - 1] == -1) cow[num - 1] = cur;
        else if(cow[num - 1] != cur)
        {
            cow[num - 1] ^= 1;
            ret++;
        }
    }
    cout << ret;
    return 0;
}