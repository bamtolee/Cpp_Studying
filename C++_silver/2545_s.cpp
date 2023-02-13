#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string tmpStr;
        vector<long long int> forVolume;
        long long int volume = 1;
        long long int d, lineSum = 0;
        getline(cin, tmpStr);
        for(int j = 0; j < 3; j++)
        {
            long long int tmp;
            cin >> tmp;
            lineSum += tmp;
            forVolume.push_back(tmp);
        }
        cin >> d;
        lineSum -= d;

        sort(forVolume.begin(), forVolume.end());
        for(int j = 3; j >= 1; j--)
        {
            long long int tmp = min(lineSum / j, forVolume[3 - j]);
            volume *= tmp;
            lineSum -= tmp;
        }
        cout << volume << "\n";
    }
    return 0;
}
