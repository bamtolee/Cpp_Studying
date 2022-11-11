#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> v(10000);

    cin >> n;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        v[tmp - 1]++;
    }
    for(int i = 0; i < 10000; i++)
    {
        while(v[i]--)
            cout << i + 1 << "\n";
    }
    return 0;
}