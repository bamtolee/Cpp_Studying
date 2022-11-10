#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> um;
    int flag = -1;

    for(int i = 0; i < 8; i++)
    {
        int tmp;
        cin >> tmp;
        um.push_back(tmp);
    }
    for(int i = 0; i < 8; i++)
    {
        if(i == 0)
        {
            if(um[i] == 1) flag = 0;
            else if(um[i] == 8) flag = 1;
            else
            {
                cout << "mixed";
                return 0;
            }
            continue;
        }
        if(flag == 0 && um[i] != i + 1)
        {
            cout << "mixed";
            return 0;
        }
        else if(flag == 1 && um[i] != 8 - i)
        {
            cout << "mixed";
            return 0;
        }
    }
    if(flag == 0) cout << "ascending";
    else if(flag == 1) cout << "descending";
    return 0;
}