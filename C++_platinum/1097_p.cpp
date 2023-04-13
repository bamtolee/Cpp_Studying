#include <iostream>
#include <string>
using namespace std;

string str[9];
int perm[9];
int visit[9];
int p[161];
int ret;

void magicCheck(int n, int k)
{
    string cur = "";
    for(int i = 0; i < n; i++)
        cur += str[perm[i]];
    
    int strs = cur.size();
    for(int i = 0; i < strs; i++)
        p[i] = 0;
    for(int i = 1, j = 0; i < strs; i++)
    {
        while(j > 0 && cur[i] != cur[j]) j = p[j - 1];
        if(cur[i] == cur[j]) p[i] = ++j;
        else p[i] = 0;
    }
    
    if(strs % (strs - p[strs - 1]) != 0)
    {
        if(k == 1)
            ret++;
        return;
    }
    int check = strs / (strs - p[strs - 1]);
    if(check == k)
        ret++;
}

void nperm(int n, int count, int k)
{
    if(count == n)
    {
        magicCheck(n, k);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(visit[i] == 1) continue;
            visit[i] = 1;
            perm[count] = i;
            nperm(n, count + 1, k);
            visit[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    cin >> k;
    
    nperm(n, 0, k);
    cout << ret;
}