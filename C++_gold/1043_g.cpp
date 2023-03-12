#include <iostream>
#include <vector>
using namespace std;

int p[51] = {0};
int knowSet[51] = {0};
vector<int> party[51];

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(a == p[a]) return a;
    else return p[a] = findSet(p[a]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if(a != b)
    {
        if(a < b) p[b] = a;
        else p[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, know, count = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        makeSet(i);
    cin >> know;
    for(int i = 0; i < know; i++)
    {
        int tmp;
        cin >> tmp;
        knowSet[tmp] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        int pn, first;
        cin >> pn >> first;
        party[i].push_back(first);
        for(int j = 1; j < pn; j++)
        {
            int num;
            cin >> num;
            unionSet(first, num);
            party[i].push_back(num);
        }
    }

    for(int i = 0; i < m; i++)
    {
        bool lieFlag = true;
        for(int j = 0; j < (int)party[i].size(); j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(knowSet[k] == 1 && findSet(k) == findSet(party[i][j]))
                {
                    lieFlag = false;
                    break;
                }
            }
            if(!lieFlag) break;
        }
        if(lieFlag) count++;
    }
    cout << count;
    return 0;
}