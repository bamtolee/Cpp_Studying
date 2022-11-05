#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ret = 0;
    vector<int> v(42);

    for(int i = 0; i < 10; i++)
    {
        int t, m;

        cin >> t;
        m = t % 42;
        v[m]++;
    }
    for (int i = 0; i < 42; i++)
    {
        if(v[i] != 0)
            ret++;
    }
    cout << ret;
    return 0;
}