#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> six;
vector<int> each;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ret = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp1, tmp2;

        cin >> tmp1 >> tmp2;
        six.push_back(tmp1);
        each.push_back(tmp2);
    }
    sort(six.begin(), six.end());
    sort(each.begin(), each.end());
    while(n >= 6)
    {
        if(each[0] * 6 > six[0]) ret += six[0];
        else ret += each[0] * 6;
        n -= 6;
    }
    if(each[0] * n > six[0]) ret += six[0];
    else ret += each[0] * n;
    cout << ret;
    return 0;
}