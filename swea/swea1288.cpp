#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        int n, visited = 0;
        int totalVisit = (1 << 10) - 1;

        cin >> n;
        int m = n;
        while(true)
        {
            int tmp = m;
            while(tmp != 0)
            {
                int k = tmp % 10;
                visited |= 1 << k;
                tmp /= 10;
            }
            if(visited == totalVisit) break;
            else
                m += n;
        }
        cout << "#" << tc << " " << m << "\n";
    }
    return 0;
}