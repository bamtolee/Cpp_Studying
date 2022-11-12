#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    queue<int> q;

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        q.push(i + 1);
    cout << "<";
    while(!q.empty())
    {
        int tmp;

        for(int i = 0; i < k - 1; i++)
        {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        if(q.size() != 1) cout << ", ";
        q.pop();
    }
    cout << ">";
    return 0;
}