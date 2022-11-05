#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, ret = 0, temp_ret;
    vector<int> v;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                temp_ret = v[i] + v[j] + v[k];
                if(temp_ret > ret && temp_ret <= m)
                    ret = temp_ret;
            }
        }
    }
    cout << ret;
    return 0;
}