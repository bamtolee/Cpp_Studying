#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ret = 0;
    vector<int> crain;
    cin >> n;
    crain.resize(n);
    for(int i = 0; i < n; i++)
        cin >> crain[i];
    cin >> m;
    vector<int> box;
    box.resize(m);
    for(int i = 0; i < m; i++)
        cin >> box[i];
    
    sort(crain.begin(), crain.end(),greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    if(box[0] > crain[0]) ret = -1;
    else
    {
        while(true)
        {
            ret++;
            int index = 0;
            for(int i = 0; i < n; i++)
            {
                for(; index < (int)box.size();)
                {
                    if(crain[i] >= box[index])
                    {
                        box.erase(box.begin() + index);
                        break;
                    }
                    index++;
                }
                if(box.size() == 0) break;
            }
            if(box.size() == 0) break;
        }
    }
    cout << ret;
    return 0;
}