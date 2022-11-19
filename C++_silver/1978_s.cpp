#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int count = 0;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(auto i : v)
    {
        if(i == 1) continue;
        int j = 2;
        for(; j * j <= i; j++)
            if(i % j == 0) break;
        if(j * j > i) count++;
    }
    cout << count;
    return 0;
}