#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int segMin[400004];

int initMin(int start, int end, int cur)
{
    if(start == end)
        return segMin[cur] = arr[start];
    int mid = (start + end) / 2;
    return segMin[cur] = min(initMin(start, mid, cur * 2), initMin(mid + 1, end, cur * 2 + 1));
}

int update(int start, int end, int cur, int index)
{
    if(index > end || index < start) return segMin[cur];
    if(start == end)
        return segMin[cur] = arr[index]; 
    int mid = (start + end) / 2;
    return segMin[cur] = min(update(start, mid, cur * 2, index),
                            update(mid + 1, end, cur * 2 + 1, index));
}

int findMin(int start, int end, int cur, int left, int right)
{
    if(left > end || right < start) return 2000000000;
    if(left <= start && end <= right) return segMin[cur];
    int mid = (start + end) / 2;
    return min(findMin(start, mid, cur * 2, left, right),
                findMin(mid + 1, end, cur * 2 + 1, left, right));
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
    initMin(1, n, 1);
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
            update(1, n, 1, j);
        }
        else if(cmd == 2)
        {
            int j, k;
            cin >> j >> k;
            cout << findMin(1, n, 1, j, k) << "\n";
        }
    }
    return 0;
}