#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int soldierCount, max = 0;
        long long int majority;
        map<long long int, int> soldierMap;
        cin >> soldierCount;

        for(int j = 0; j < soldierCount; j++)
        {
            long long int soldierNum;
            cin >> soldierNum;
            int tmpMax = ++soldierMap[soldierNum];

            if(tmpMax > max)
            {
                max = tmpMax;
                majority = soldierNum;
            }
        }
        if(max > soldierCount / 2) cout << majority << "\n";
        else cout << "SYJKGW\n";
    }
    return 0;
}