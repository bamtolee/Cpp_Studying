#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    int num_backind, flag;

    while(1)
    {
        flag = 0;
        cin >> num;
        if(num == "0") return 0;
        if(num.size() == 1)
        {
            cout << "yes" << "\n";
            continue;
        }
        num_backind = num.size() - 1;
        for(int i = 0; i < num.size() / 2; i++)
        {
            if(num[i] != num[num_backind]) flag = 1;
            num_backind--;
        }
        if (flag == 1) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }
}