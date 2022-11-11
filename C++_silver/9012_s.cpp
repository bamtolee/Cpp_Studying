#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        int count = 0;

        cin >> str;
        for(auto i : str)
        {
            if(i == '(') count++;
            else count--;
            if(count < 0) break;
        }
        if(count == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}