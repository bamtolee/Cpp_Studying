#include <iostream>
#include <string>
using namespace std;

bool winCheck(string str, char target)
{
    if(str[0] == target && str[1] == target && str[2] == target)
        return true;
    else if(str[3] == target && str[4] == target && str[5] == target)
        return true;
    else if(str[6] == target && str[7] == target && str[8] == target)
        return true;
    else if(str[0] == target && str[3] == target && str[6] == target)
        return true;
    else if(str[1] == target && str[4] == target && str[7] == target)
        return true;
    else if(str[2] == target && str[5] == target && str[8] == target)
        return true;
    else if(str[0] == target && str[4] == target && str[8] == target)
        return true;
    else if(str[2] == target && str[4] == target && str[6] == target)
        return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true)
    {
        string tmp;
        cin >> tmp;
        if(tmp.compare("end") == 0) break;

        int Xcount = 0;
        int Ocount = 0;
        for(int i = 0; i < 9; i++)
        {   
            if(tmp[i] == 'X') Xcount++;
            else if(tmp[i] == 'O') Ocount++;
        }
        if(Xcount < Ocount) cout << "invalid\n";
        else if(Xcount - Ocount >= 2) cout << "invalid\n";
        else
        {
            if(Xcount > Ocount)
            {
                if(winCheck(tmp, 'X'))
                {
                    if(!winCheck(tmp, 'O'))
                        cout << "valid\n";
                    else cout << "invalid\n";
                }
                else
                {
                    if(!winCheck(tmp, 'O') && Xcount == 5 && Ocount == 4)
                        cout << "valid\n";
                    else cout << "invalid\n";
                }
            }
            else
            {
                if(winCheck(tmp, 'O'))
                {
                    if(!winCheck(tmp, 'X'))
                        cout << "valid\n";
                    else cout << "invalid\n";
                }
                else cout << "invalid\n";
            }
        }
    }
    return 0;
}