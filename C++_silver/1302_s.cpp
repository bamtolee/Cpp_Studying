#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string b_name;
    map<string, int> m;
    map<string, int>::iterator iter;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> b_name;
        if(m.find(b_name) == m.end())
        {
            m[b_name] = 1;
        }
        else
            m[b_name]++;
    }
    iter = max_element(m.begin(), m.end(), [](auto &x, auto &y){
        return x.second < y.second;
    });
    cout << iter->first;
    return 0;
}