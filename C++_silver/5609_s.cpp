#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, ret = 1;
    int **saikorou;
    string tmp;

    saikorou = new int*[3];
    for(int i = 0; i < 3; i++)
        saikorou[i] = new int[4];
    saikorou[0][1] = 5;
    saikorou[1][0] = 4;
    saikorou[1][1] = 6;
    saikorou[1][2] = 3;
    saikorou[1][3] = 1;
    saikorou[2][1] = 2;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp == "North")
        {
            int temp = saikorou[1][3];
            saikorou[1][3] = saikorou[2][1];
            saikorou[2][1] = saikorou[1][1];
            saikorou[1][1] = saikorou[0][1];
            saikorou[0][1] = temp;
        }
        else if(tmp == "South")
        {
            int temp = saikorou[1][3];
            saikorou[1][3] = saikorou[0][1];
            saikorou[0][1] = saikorou[1][1];
            saikorou[1][1] = saikorou[2][1];
            saikorou[2][1] = temp;
        }
        else if(tmp == "East")
        {
            int temp = saikorou[1][3];
            saikorou[1][3] = saikorou[1][0];
            saikorou[1][0] = saikorou[1][1];
            saikorou[1][1] = saikorou[1][2];
            saikorou[1][2] = temp;
        }
        else if(tmp == "West")
        {
            int temp = saikorou[1][3];
            saikorou[1][3] = saikorou[1][2];
            saikorou[1][2] = saikorou[1][1];
            saikorou[1][1] = saikorou[1][0];
            saikorou[1][0] = temp;
        }
        else if(tmp == "Right")
        {
            int temp = saikorou[2][1];
            saikorou[2][1] = saikorou[1][2];
            saikorou[1][2] = saikorou[0][1];
            saikorou[0][1] = saikorou[1][0];
            saikorou[1][0] = temp;
        }
        else if(tmp == "Left")
        {
            int temp = saikorou[2][1];
            saikorou[2][1] = saikorou[1][0];
            saikorou[1][0] = saikorou[0][1];
            saikorou[0][1] = saikorou[1][2];
            saikorou[1][2] = temp;
        }
        ret += saikorou[1][3];
    }
    cout << ret;
}