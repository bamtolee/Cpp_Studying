#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> ret;
    int n;
    cin >> n;

    for(int i = 0; i < 999; i++)
        ret.push_back(1);
    for(int i = 0; i < 1000; i++)
        ret.push_back(1000);
    cout << ret.size() << "\n";
    for(auto i : ret)
        cout << i << " ";
    return 0;
}