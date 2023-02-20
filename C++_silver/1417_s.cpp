#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, dasom, ret = 0;
    priority_queue<int> pq;

    cin >> n;
    cin >> dasom;
    for(int i = 0; i < n - 1; i++)
    {
        int tmp;

        cin >> tmp;
        pq.push(tmp);
    }
    if(n != 1)
    {
        while(true)
        {
            int tmp = pq.top();
            pq.pop();
            if(dasom <= tmp)
            {
                tmp--;
                dasom++;
                ret++;
            }
            else
                break;
            pq.push(tmp);
        }
    }
    cout << ret;
    return 0;
}