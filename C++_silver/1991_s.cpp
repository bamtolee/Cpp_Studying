#include <iostream>
#include <vector>
using namespace std;

vector<char> tr[26];

void preorderT(int cur)
{
    char c = cur + 'A';
    cout << c;
    if(tr[cur][0] != '.') preorderT(tr[cur][0] - 'A');
    if(tr[cur][1] != '.') preorderT(tr[cur][1] - 'A');
}

void inorderT(int cur)
{
    char c = cur + 'A';
    if(tr[cur][0] != '.') inorderT(tr[cur][0] - 'A');
    cout << c;
    if(tr[cur][1] != '.') inorderT(tr[cur][1] - 'A');
}

void postorderT(int cur)
{
    char c = cur + 'A';
    if(tr[cur][0] != '.') postorderT(tr[cur][0] - 'A');
    if(tr[cur][1] != '.') postorderT(tr[cur][1] - 'A');
    cout << c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char a, l, r;

        cin >> a >> l >> r;
        tr[a - 'A'].push_back(l);
        tr[a - 'A'].push_back(r);
    }

    preorderT(0);
    cout << "\n";
    inorderT(0);
    cout << "\n";
    postorderT(0);
    return 0;
}