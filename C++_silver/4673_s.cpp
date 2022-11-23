#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[10001] = {0};
    int mid, j;
    
    for(int i = 1; i <= 10000; i++)
    {
        mid = i;
        j = i;
        while(j != 0)
        {
            mid += j % 10;
            j /= 10;
        }
        if(mid <= 10000) a[mid] = 1;
    }
    for(int i = 1; i <= 10000; i++)
        if(a[i] == 0) cout << i << "\n";
    return 0;
}