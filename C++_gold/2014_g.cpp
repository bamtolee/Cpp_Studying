#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for(int i = 0; i < k; i++)
        pq.push(v[i]);
    int prev = -1;
    for(int i = 0; i < n - 1; i++)
    {
        int cur = pq.top();
        pq.pop();
        if(prev == cur)
        {
            i--;
            continue;
        }
        for(int j = 0; j < k; j++)
        {
            ll tmp = (ll)cur * (ll)v[j];
            if(tmp >= 2147483648) continue;
            pq.push((int)tmp);
        }
        prev = cur;
    }
    while(prev == pq.top())
        pq.pop();
    cout << pq.top();
    return 0;
}