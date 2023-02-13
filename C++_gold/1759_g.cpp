#include <iostream>
#include <algorithm>
using namespace std;

bool validPwd(int l, char *combRet)
{
    int vowel = 0, conso = 0;

    for(int i = 0; i < l; i++)
    {
        if(combRet[i] == 'a' || combRet[i] == 'e' || combRet[i] == 'i' || combRet[i] == 'o' || combRet[i] == 'u')
            vowel++;
        else conso++;
    }
    if(vowel >= 1 && conso >= 2) return true;
    else return false;
}

void combinationL(int count, int start, int l, int c, char *pwd, char *combRet)
{
    if(count == l)
    {
        if(validPwd(l, combRet))
        {
            for(int i = 0; i < l; i++)
                cout << combRet[i];
            cout << "\n";
        }
        return;
    }
    else
    {
        for(int i = start; i < c; i++)
        {
            combRet[count] = pwd[i];
            combinationL(++count, ++start, l, c, pwd, combRet);
            count--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int l, c;
    char *pwd, *combRet;
    cin >> l >> c;
    pwd = new char[c];
    combRet = new char[l]; 
    for(int i = 0; i < c; i++)
        cin >> pwd[i];

    sort(pwd, pwd + c);
    combinationL(0, 0, l, c, pwd, combRet);
    return 0;
}