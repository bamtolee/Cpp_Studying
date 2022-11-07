#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool str_length_compare(string s1, string s2)
{
    if(s1.length() != s2.length())
        return s1.length() < s2.length();
    else
        return s1 < s2;
}

int main()
{
    vector<string> v;
    string s;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), str_length_compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto i : v)
    {
        cout << i << "\n";
    }
    return 0;
}