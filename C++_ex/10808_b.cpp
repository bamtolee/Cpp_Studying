#include <iostream>
using namespace std;

int main()
{
    char *str;
    int num[26] = {0};

    str = new char[102];
    cin >> str;
    for(int i = 0; str[i] != '\0'; i++)
        num[str[i] - 97]++;
    for(int i = 0; i < 26; i++)
        cout << num[i] << " ";
    delete[] str;
    return 0;
}