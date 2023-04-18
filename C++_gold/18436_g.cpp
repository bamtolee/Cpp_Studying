#include <iostream>
using namespace std;

int arr[100001];
int segOdd[400004];
int segEven[400004];

int initOdd(int start, int end, int cur)
{
    if(start == end)
    {
        if((arr[start] & 1) != 0)
            return segOdd[cur] = 1;
        else
            return segOdd[cur] = 0;
    }
    int mid = (start + end) / 2;
    return segOdd[cur] = initOdd(start, mid, cur * 2) + initOdd(mid + 1, end, cur * 2 + 1);
}

int initEven(int start, int end, int cur)
{
    if(start == end)
    {
        if((arr[start] & 1) == 0)
            return segEven[cur] = 1;
        else
            return segEven[cur] = 0;
    }
    int mid = (start + end) / 2;
    return segEven[cur] = initEven(start, mid, cur * 2) + initEven(mid + 1, end, cur * 2 + 1);
}

int updateOdd(int start, int end, int cur, int index)
{
    if(index > end || index < start) return segOdd[cur];
    if(start == end)
    {
        if((arr[start] & 1) != 0)
            return segOdd[cur] = 1;
        else
            return segOdd[cur] = 0;
    }
    
    int mid = (start + end) / 2;
    return segOdd[cur] = updateOdd(start, mid, cur * 2, index)
                    + updateOdd(mid + 1, end, cur * 2 + 1, index);
}

int updateEven(int start, int end, int cur, int index)
{
    if(index > end || index < start) return segEven[cur];
    if(start == end)
    {
        if((arr[start] & 1) == 0)
            return segEven[cur] = 1;
        else
            return segEven[cur] = 0;
    }
    
    int mid = (start + end) / 2;
    return segEven[cur] = updateEven(start, mid, cur * 2, index)
                    + updateEven(mid + 1, end, cur * 2 + 1, index);
}

int findOdd(int start, int end, int cur, int left, int right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segOdd[cur];
    
    int mid = (start + end) / 2;
    return findOdd(start, mid, cur * 2, left, right)
            + findOdd(mid + 1, end, cur * 2 + 1, left, right);
}

int findEven(int start, int end, int cur, int left, int right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segEven[cur];
    
    int mid = (start + end) / 2;
    return findEven(start, mid, cur * 2, left, right)
            + findEven(mid + 1, end, cur * 2 + 1, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    initOdd(1, n, 1);
    initEven(1, n, 1);
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int cmd;
        cin >> cmd;
        if(cmd == 1)
        {
            int j, v;
            cin >> j >> v;
            arr[j] = v;
            updateOdd(1, n, 1, j);
            updateEven(1, n, 1, j);
        }
        else if(cmd == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << findEven(1, n, 1, l, r) << "\n";
        }
        else if(cmd == 3)
        {
            int l, r;
            cin >> l >> r;
            cout << findOdd(1, n, 1, l, r) << "\n";
        }
    }
    return 0;
}