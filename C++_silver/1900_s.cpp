#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
vector <p> wres;
vector <p> winC;

bool compare(p a, p b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        wres.push_back({a, b});
    }

    for(int i = 0; i < n; i++)
    {
        int tmpS = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            int iP = wres[i].first + wres[i].second * wres[j].first;
            int jP = wres[j].first + wres[j].second * wres[i].first;
            if(iP > jP) tmpS++;
        }
        winC.push_back({i + 1, tmpS});
    }
    sort(winC.begin(), winC.end(), compare);
    for(int i = 0; i < winC.size(); i++)
        cout << winC[i].first << "\n";
    return 0;
}
