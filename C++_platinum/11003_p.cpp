#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> EleIndex;
deque<EleIndex> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(!dq.empty() && dq.front().second <= i - l) dq.pop_front();
        if(dq.empty()) dq.push_back({x, i});
        else
        {
            while(!dq.empty() && dq.back().first > x)
                dq.pop_back();
            dq.push_back({x, i});
        }
        cout << dq.front().first << " ";
    }
    return 0;
}