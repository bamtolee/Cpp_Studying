#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> line;
vector<line> v;

struct compare{
    bool operator()(line a, line b){
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());
    priority_queue<line, vector<line>, compare> pq;
    pq.push(v[0]);
    int maxRet = 1;
    for(int i = 1; i < n; i++)
    {
        line cur = v[i];
        if(cur.first < pq.top().second)
        {
            pq.push(cur);
            if(maxRet < (int)pq.size()) maxRet = (int)pq.size();
        }
        else
        {
            while(!pq.empty() && cur.first >= pq.top().second)
                pq.pop();
            pq.push(cur);
        }
    }
    cout << maxRet;
    return 0;
}