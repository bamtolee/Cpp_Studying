#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s_hour, e_hour, congs_hour, conge_hour;
    int max_con = 0;
    string name, place, cong_place;
    map<string, tuple<string, int, int>> m;
    map<string, vector<int>> congestion_m;
    map<string, vector<int>>::iterator iter;
    bool flag = false;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> place >> s_hour >> e_hour;
        if(m.find(name) == m.end())
        {
            m[name] = make_tuple(place, s_hour, e_hour);
            if(congestion_m.find(place) == congestion_m.end())
            {
                vector<int> tmp_v(50001);
                congestion_m[place] = tmp_v;
            }
            for(int j = s_hour; j < e_hour; j++)
                congestion_m[place][j]++;
        }
    }
    for(iter = congestion_m.begin(); iter != congestion_m.end(); iter++)
    {
        for(int i = 1; i <= 50000; i++)
        {
            if(iter->second[i] > max_con)
            {
                max_con = iter->second[i];
                congs_hour = i;
                cong_place = iter->first;
                flag = true;
            }
            if(flag == true && iter->second[i] != max_con)
            {
                flag = false;
                conge_hour = i;
            }
        }
    }
    cout << cong_place << " " << congs_hour << " " << conge_hour;
    return 0;
}