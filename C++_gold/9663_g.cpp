#include <iostream>
#include <cmath>
using namespace std;

int queen[16];
int visit[16] = {0};
int ret = 0;

bool queenPossibleCheck(int i, int count)
{
    if(count == 0) return true;
    else
        for(int j = 0; j < count; j++)
            if(abs(queen[j] - i) == count - j) return false;
    return true;
}

void queenRecur(int n, int count)
{
    if(count == n) ret++;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(visit[i] == 0)
            {
                if(!queenPossibleCheck(i, count)) continue;
                visit[i] = 1;
                queen[count] = i;
                queenRecur(n, count + 1);
                visit[i] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    queenRecur(n, 0);
    cout << ret;
    return 0;
}