#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n = 1;
    int a, b, ret = 0;
    int count = 0;

    for(int i = 0; i < 1000; i++)
    {
        v.push_back(n);
        count++;
        if(n == count)
        {
            n++;
            count = 0;
        }
    }
    cin >> a >> b;
    for(int i = a - 1; i <= b - 1; i++)
    {
        ret += v[i];
    }
    cout << ret;
    return 0;
}