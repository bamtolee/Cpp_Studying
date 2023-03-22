#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> happy;
vector<int> piro;
vector<int> youngHappy;
vector<int> youngPiro;
vector<int> nyHappy;
vector<int> nyPiro;
int maxValue = -1000000000;
int minValue = 1111111111;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x1, x2;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> x2;
        happy.push_back(x1);
        piro.push_back(x2);
    }

    int minHappy = minValue;
    int maxPiro = maxValue;
    for(int i = 0; i < n; i++)
    {
        if(minHappy > happy[i] && happy[i] != 0) minHappy = happy[i];
        if(maxPiro < piro[i]) maxPiro = piro[i];
        youngHappy.push_back(minHappy);
        youngPiro.push_back(maxPiro);
    }
    int maxHappy = maxValue;
    int minPiro = minValue;
    nyHappy.resize(n);
    nyPiro.resize(n);
    for(int i = n - 1; i >= 0; i--)
    {
        if(maxHappy < happy[i]) maxHappy = happy[i];
        if(minPiro > piro[i] && piro[i] != 0) minPiro = piro[i];
        nyHappy[i] = maxHappy;
        nyPiro[i] = minPiro;
    }
    
    int k = -2;
    for(int i = 0; i < n - 1; i++)
        if(nyHappy[i + 1] < youngHappy[i] && nyPiro[i + 1] > youngPiro[i])
            k = i;

    cout << k + 1;
    return 0;
}