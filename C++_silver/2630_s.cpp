#include <iostream>
using namespace std;

int paper[128][128];
int white = 0;
int blue = 0;

void colourCheck(int r, int c, int n)
{
    int tmpSum = 0;
    
    for(int i = r; i < r + n; i++)
        for(int j = c; j < c + n; j++)
            tmpSum += paper[i][j];
    if(tmpSum == n * n) blue++;
    else if(tmpSum == 0) white++;
    else
    {
        colourCheck(r, c, n / 2);
        colourCheck(r + n / 2, c, n / 2);
        colourCheck(r, c + n / 2, n / 2);
        colourCheck(r + n /2, c + n / 2, n / 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];

    colourCheck(0, 0, n);
    cout << white << "\n" << blue;
    return 0;
}