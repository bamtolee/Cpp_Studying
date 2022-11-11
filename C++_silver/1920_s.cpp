#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, tmp;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << binary_search(v.begin(), v.end(), tmp) << "\n";
    }
    return 0;
}