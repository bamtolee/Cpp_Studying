#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        vector<vector<int>> v;
        
        cin >> n >> m;
        for (int j = 0; j <= m; j++)
        {
            v.push_back(vector<int>());
            for(int k = 0; k <= j; k++)
            {
                if(k == 0 || j == k)
                    v[j].push_back(1);
                else
                    v[j].push_back(v[j - 1][k - 1] + v[j - 1][k]);
            }
        }
        cout << v[m][n] << "\n";
    }
    return 0;
}