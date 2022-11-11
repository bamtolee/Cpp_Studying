#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, ret = 100;
    vector<string> v;
    string BW[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
    string WB[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string tmp;

        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i <= n - 8; i++)
    {
        for(int j = 0; j <= m - 8; j++)
        {
            int count_w = 0;
            int count_b = 0;
            int mid;
            
            for(int k = 0; k < 8; k++)
            {
                for(int t = 0; t < 8; t++)
                    if(v[i + k][j + t] != BW[k][t]) count_b++; 
            }
            for(int k = 0; k < 8; k++)
            {
                for(int t = 0; t < 8; t++)
                    if(v[i + k][j + t] != WB[k][t]) count_w++; 
            }
            mid = min(count_b, count_w);
            ret = min(ret, mid);
        }
    }
    cout << ret;
    return 0;
}