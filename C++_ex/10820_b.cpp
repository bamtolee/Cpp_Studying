#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int num1, num2, num3, num4;

    while(1)
    {
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
        getline(cin, str);
        if(str[0] == '\0') break;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ') num4++;
            else if(str[i] >= 97 && str[i] <= 122) num1++;
            else if(str[i] >= 65 && str[i] <= 90) num2++;
            else if(str[i] >= 48 && str[i] <= 57) num3++;
        }
        cout << num1 << " " << num2 << " " << num3 << " " << num4 << "\n";
    }
    return 0;
}