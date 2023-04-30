#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        string s;
        cin >> s;

        int alpha[26] = {0};
        vector<char> ret;
        for(int i = 0; i < (int)s.size(); i++)
            alpha[s[i] - 'A']++;

        if(alpha['Z' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['Z' - 'A']--)
            {
                count++;
                ret.push_back('0');
            }
            for(int i = 0; i < (int)num[0].size(); i++)
            {
                if(alpha[num[0][i] - 'A'] != 0)
                    alpha[num[0][i] - 'A'] -= count;
            }
        }
        if(alpha['W' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['W' - 'A']--)
            {
                count++;
                ret.push_back('2');
            }
            for(int i = 0; i < (int)num[2].size(); i++)
            {
                if(alpha[num[2][i] - 'A'] != 0)
                    alpha[num[2][i] - 'A'] -= count;
            }
        }
        if(alpha['U' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['U' - 'A']--)
            {
                count++;
                ret.push_back('4');
            }
            for(int i = 0; i < (int)num[4].size(); i++)
            {
                if(alpha[num[4][i] - 'A'] != 0)
                    alpha[num[4][i] - 'A'] -= count;
            }
        }
        if(alpha['X' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['X' - 'A']--)
            {
                count++;
                ret.push_back('6');
            }
            for(int i = 0; i < (int)num[6].size(); i++)
            {
                if(alpha[num[6][i] - 'A'] != 0)
                    alpha[num[6][i] - 'A'] -= count;
            }
        }
        if(alpha['G' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['G' - 'A']--)
            {
                count++;
                ret.push_back('8');
            }
            for(int i = 0; i < (int)num[8].size(); i++)
            {
                if(alpha[num[8][i] - 'A'] != 0)
                    alpha[num[8][i] - 'A'] -= count;
            }
        }

        if(alpha['F' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['F' - 'A']--)
            {
                count++;
                ret.push_back('5');
            }
            for(int i = 0; i < (int)num[5].size(); i++)
            {
                if(alpha[num[5][i] - 'A'] != 0)
                    alpha[num[5][i] - 'A'] -= count;
            }
        }
        if(alpha['V' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['V' - 'A']--)
            {
                count++;
                ret.push_back('7');
            }
            for(int i = 0; i < (int)num[7].size(); i++)
            {
                if(alpha[num[7][i] - 'A'] != 0)
                    alpha[num[7][i] - 'A'] -= count;
            }
        }
        if(alpha['R' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['R' - 'A']--)
            {
                count++;
                ret.push_back('3');
            }
            for(int i = 0; i < (int)num[3].size(); i++)
            {
                if(alpha[num[3][i] - 'A'] != 0)
                    alpha[num[3][i] - 'A'] -= count;
            }
        }
        if(alpha['O' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['O' - 'A']--)
            {
                count++;
                ret.push_back('1');
            }
            for(int i = 0; i < (int)num[1].size(); i++)
            {
                if(alpha[num[1][i] - 'A'] != 0)
                    alpha[num[1][i] - 'A'] -= count;
            }
        }
        if(alpha['I' - 'A'] > 0)
        {
            int count = 0;
            while(alpha['I' - 'A']--)
            {
                count++;
                ret.push_back('9');
            }
            for(int i = 0; i < (int)num[9].size(); i++)
            {
                if(alpha[num[9][i] - 'A'] != 0)
                    alpha[num[9][i] - 'A'] -= count;
            }
        }
        sort(ret.begin(), ret.end());
        cout << "Case #" << tc << ": ";
        for(int i = 0; i < (int)ret.size(); i++)
            cout << ret[i];
        cout << "\n";
    }
    return 0;
}