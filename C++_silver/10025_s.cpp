#include <iostream>
using namespace std;

int field[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int g, x;
        cin >> g >> x;
        field[x] = g;
    }

    int maxRet = 0, tmpSum = 0;
    int left = 0, right = k * 2 >= 1000000 ? 1000000 : k * 2;
    for(int i = left; i <= right; i++)
        maxRet += field[i];
    tmpSum = maxRet;
    for(int i = right + 1; i <= 1000000; i++)
    {
        tmpSum -= field[left];
        tmpSum += field[i];
        left++;
        if(tmpSum > maxRet) maxRet = tmpSum;
    }
    cout << maxRet;
    return 0;
}