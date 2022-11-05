// 같은 2750이지만 new를 이용한 배열 동적 할당이 아닌
// vector로 해결해 봄.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";
    return 0;
}