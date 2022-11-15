#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    float a;
    string op;

    cout << fixed;
    cout.precision(2);
    cin >> t;
    while(t--)
    {
        cin >> a;
        cin.ignore();
        getline(cin, op);
        for(auto i : op)
        {
            if(i == '@') a *= 3;
            else if(i == '%') a += 5;
            else if(i == '#') a -= 7;
        }
        cout << a << "\n";
    }
    return 0;
}