#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int segMin[400004];
int segMax[400004];

int initMin(int start, int end, int cur)
{
    if(start == end)
        return segMin[cur] = arr[start];
    int mid = (start + end) / 2;
    return segMin[cur] = min(initMin(start, mid, cur * 2), initMin(mid + 1, end, cur * 2 + 1));
}

int initMax(int start, int end, int cur)
{
    if(start == end)
        return segMax[cur] = arr[start];
    int mid = (start + end) / 2;
    return segMax[cur] = max(initMax(start, mid, cur * 2), initMax(mid + 1, end, cur * 2 + 1));
}

int findMin(int start, int end, int cur, int left, int right)
{
    if(left > end || right < start) return 2000000000;
    if(left <= start && end <= right) return segMin[cur];
    int mid = (start + end) / 2;
    return min(findMin(start, mid, cur * 2, left, right),
            findMin(mid + 1, end, cur * 2 + 1, left, right));
}

int findMax(int start, int end, int cur, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segMax[cur];
    int mid = (start + end) / 2;
    return max(findMax(start, mid, cur * 2, left, right),
            findMax(mid + 1, end, cur * 2 + 1, left, right));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    initMin(1, n, 1);
    initMax(1, n, 1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << findMin(1, n, 1, a, b) << " " << findMax(1, n, 1, a, b) << "\n";
    }
    return 0;
}