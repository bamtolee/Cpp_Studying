#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, mid;
    queue<int> q;

    while(1)
    {
        cin >> n;
        if(n == -1) break;
        else
        {
            mid = 0;
            for(int i = 1; i <= n / 2; i++)
            {
                if(n % i == 0) 
                {
                    mid += i;
                    q.push(i);
                }
            }
            if(mid == n)
            {
                cout << n << " = ";
                while(!q.empty())
                {
                    cout << q.front();
                    q.pop();
                    if(!q.empty()) cout << " + ";
                }
            }
            else cout << n << " is NOT perfect.";
            while(!q.empty()) q.pop();
        }
        cout << "\n";
    }
    return 0;
}