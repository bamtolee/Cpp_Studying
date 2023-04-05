#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, *p;
    vector<char> pattern;
    vector<char> roulette;
    cin >> n;
    p = new int[n + 1];
    for(int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        pattern.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        roulette.push_back(tmp);
    }
    for(int i = 0; i < n - 1; i++)
        roulette.push_back(roulette[i]);

    p[0] = 0;
    for(int i = 1, j = 0; i < (int)pattern.size(); i++)
    {
        while(j > 0 && pattern[i] != pattern[j]) j = p[j - 1];
        if(pattern[i] == pattern[j]) p[i] = ++j;
        else p[i] = 0;
    }
    
    int count = 0;
    for(int i = 0, j = 0; i < (int)roulette.size(); i++)
    {
        while(j > 0 && roulette[i] != pattern[j]) j = p[j - 1];
        if(roulette[i] == pattern[j])
        {
            if(j == (int)pattern.size() - 1)
            {
                count++;
                j = p[j];
            }
            else j++;
        }
    }

    int gcdX = gcd(n, count);
    n /= gcdX;
    count /= gcdX;
    if(count > n) cout << "1/1";
    else cout << count << "/" << n;
    return 0;
}