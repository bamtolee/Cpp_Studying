#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> lineInfor;
vector<lineInfor> hole;
int aqua[40001];
int remain[40001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, tmp1, tmp2, tmp3, tmp4;
    int maxXI = 0;
    cin >> n >> tmp1 >> tmp2;
    for(int i = 0; i < (n - 2) / 2; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        for(int i = tmp1; i < tmp3; i++)
        {
            aqua[i] = tmp2;
            remain[i] = tmp2;
        }
        maxXI = tmp3;
    }
    cin >> tmp1 >> tmp2;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        hole.push_back({{tmp1, tmp3}, tmp2});
    }

    sort(hole.begin(), hole.end());
    for(int i = 0; i < k; i++)
    {
        int left = hole[i].first.first;
        int right = hole[i].first.second;
        int h = hole[i].second;
        for(int j = left; j < right; j++)
            remain[j] = 0;
        for(int j = left - 1; j >= 0; j--)
        {
            if(h > aqua[j]) h = aqua[j];
            remain[j] = min(remain[j], aqua[j] - h);
            if(remain[j] < 0) remain[j] = 0;
        }
        h = hole[i].second;
        for(int j = right; j < maxXI; j++)
        {
            if(h > aqua[j]) h = aqua[j];
            remain[j] = min(remain[j], aqua[j] - h);
            if(remain[j] < 0) remain[j] = 0;
        }
    }
    
    int ret = 0;
    for(int i = 0; i < maxXI; i++)
        ret += remain[i];
    cout << ret;
    return 0;
}