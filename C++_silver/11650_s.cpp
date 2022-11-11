#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> co;

int main()
{
    int n;
    vector<co> v;

    cin >> n;
    while(n--)
    {
        int x, y;
        co tmp;

        cin >> x >> y;
        tmp = make_pair(x, y);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(auto i : v)
        cout << i.first << " " << i.second << "\n";
    return 0;
}