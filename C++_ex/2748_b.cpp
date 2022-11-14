#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<long long int> v;

    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        if(i == 0) v.push_back(0);
        else if(i == 1) v.push_back(1);
        else
        {
            v.push_back(v[i - 2] + v[i - 1]);
        }
    }
    cout << v[n];
    return 0;
}