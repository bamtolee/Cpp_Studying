#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    vector<string> v;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
        v.push_back(str.substr(i));
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << "\n";
    return 0;
}