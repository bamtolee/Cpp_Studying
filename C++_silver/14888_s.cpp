#include <iostream>
#include <algorithm>
using namespace std;

void per(int n, int *num, char *computeMode, char *ret, bool *visit, int count, int &max, int &min)
{
    if(count == n - 1)
    {
        int mid = num[0];
        for(int i = 1; i < n; i++)
        {
            if(ret[i - 1] == 'a')
                mid += num[i];
            else if(ret[i - 1] == 's')
                mid -= num[i];
            else if(ret[i - 1] == 'm')
                mid *= num[i];
            else if(ret[i - 1] == 'd')
                mid /= num[i];
        }
        if(max < mid) max = mid;
        if(min > mid) min = mid;
        return;
    }
    else
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(visit[i] == true) continue;
            else
            {
                ret[count] = computeMode[i];
                visit[i] = true;
                per(n, num, computeMode, ret, visit, ++count, max, min);
                visit[i] = false;
                count--;
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, *num, max = -1000000000, min = 1000000000;
    char *computeMode, *ret;
    bool *visit;
    cin >> n;
    num = new int[n];
    computeMode = new char[n - 1];
    ret = new char[n - 1];
    visit = new bool[n - 1];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < n - 1; i++)
        visit[i] = false;

    int tmpIndex = 0;
    for(int i = 0; i < 4; i++)
    {
        int tmp;
        cin >> tmp;
        
        if(i == 0)
        {
            for(int j = 0; j < tmp; j++)
            {
                computeMode[tmpIndex] = 'a';
                tmpIndex++;
            }
        }
        else if(i == 1)
        {
            for(int j = 0; j < tmp; j++)
            {
                computeMode[tmpIndex] = 's';
                tmpIndex++;
            }
        }
        else if(i == 2)
        {
            for(int j = 0; j < tmp; j++)
            {
                computeMode[tmpIndex] = 'm';
                tmpIndex++;
            }
        }
        else if(i == 3)
        {
            for(int j = 0; j < tmp; j++)
            {
                computeMode[tmpIndex] = 'd';
                tmpIndex++;
            }
        }
    }
    sort(computeMode, computeMode + n - 1);
    per(n, num, computeMode, ret, visit, 0, max, min);
    cout << max << "\n" << min;
    return 0;
}