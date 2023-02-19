#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> input(16);

void payCal(int index, int n, int &maxRet, int pay, int last)
{
    maxRet = max(maxRet, pay);
    if(index + 1 > n) return;
    payCal(index + 1, n, maxRet, pay, last);
    if(last <= index && index + input[index].first <= n)
        payCal(index + 1, n, maxRet, pay + input[index].second, index + input[index].first);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, maxRet = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> input[i].first >> input[i].second;
    
    payCal(0, n, maxRet, 0, 0);
    cout << maxRet;
    return 0;
}