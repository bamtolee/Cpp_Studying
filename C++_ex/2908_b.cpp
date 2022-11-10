#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    int ia, ib;

    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ia = stoi(a);
    ib = stoi(b);
    if(ia > ib) cout << ia;
    else cout << ib;
    return 0;
}