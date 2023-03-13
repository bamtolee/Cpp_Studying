#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string inputA, inputB;
        cin >> inputA >> inputB;
        string tmp1 = regex_replace(inputA, regex("_"), "[A-Z]+");
        string tmp2 = regex_replace(inputA, regex("_"), "");

        if(regex_match(inputB, regex(tmp2))) cout << "_\n";
        else if(regex_match(inputB, regex(tmp1)))
        {
            for(int i = 0; i < 26; i++)
            {
                char c = 'A' + i;
                string copy = inputA;
                int k = copy.find("_");
                copy[k] = c;
                if(regex_match(inputB, regex(copy)))
                {
                    cout << c << "\n";
                    break;
                }
            }
        }
        else if(!regex_match(inputB, regex(tmp1))) cout << "!\n";
    }
    return 0;
}