#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int zero = 0b111101101101111;
int one = 0b001001001001001;
int two = 0b111001111100111;
int three = 0b111001111001111;
int four = 0b101101111001001;
int five = 0b111100111001111;
int six = 0b111100111101111;
int seven = 0b111001001001001;
int eight = 0b111101111101111;
int nine = 0b111101111001111;
int number[10] = {zero, one, two, three, four, five, six, seven, eight, nine};

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int num[4] = {0};
    int ret[4];
    string tmp;

    for(int i = 14; i >= 0; )
    {
        for(int j = 0; j < 4; j++)
        {
            int t = i;

            cin >> tmp;
            for(int k = 0; k < tmp.size(); k++)
            {
                if(tmp[k] == '#') num[j] += (int)pow(2, t);
                t--;
            }
        }
         i -= 3;
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if((num[i] | number[j]) == number[j])
            {
                ret[i] = j;
                break;
            }
        }
    }
    cout << ret[0] << ret[1] << ":" << ret[2] << ret[3];
}