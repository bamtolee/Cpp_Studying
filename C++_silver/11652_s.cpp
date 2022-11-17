#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, max = 0;
    long long int a, ret;
    map<long long int, int> m;
    map<long long int, int>::iterator iter;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(m.find(a) == m.end()) m.insert(make_pair(a, 1));
        else
        {
            iter = m.find(a);
            iter->second++;
        }
    }
    for(auto i : m)
    {
        if(i.second > max)
        {
            max = i.second;
            ret = i.first;
        }
    }
    cout << ret;
    return 0;
}