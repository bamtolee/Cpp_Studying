#include <iostream>
using namespace std;

int pSum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s, min = 10000000;
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        pSum[i] = pSum[i - 1] + tmp;
    }

    int index1 = 0, index2 = 1;
    while(index2 <= n)
    {
        if(pSum[index2] - pSum[index1] < s) index2++;
        else
        {
            if(min > index2 - index1) min = index2 - index1;
            index1++;
        }
    }
    if(min == 10000000) cout << 0;
    else cout << min;
    return 0;
}