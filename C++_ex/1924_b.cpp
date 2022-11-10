#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> each_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> day_name = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int x, y, mid = 0;

    cin >> x >> y;
    for(int i = 1; i < x; i++)
    {
        mid += each_day[i - 1];
    }
    mid += y;
    cout << day_name[mid % 7];
    return 0;
}