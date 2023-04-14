#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int seg[400004];

int init(int start, int end, int cur)
{
    if(start == end)
        return seg[cur] = arr[start];
    int mid = (start + end) / 2;
    return seg[cur] = min(init(start, mid, cur * 2), init(mid + 1, end, cur * 2 + 1));
}

int findMin(int start, int end, int cur, int left, int right)
{
    if(left > end || right < start) return 2000000000;
    if(left <= start && end <= right) return seg[cur];
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, n, 1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << findMin(1, n, 1, a, b) << "\n";
    }
    return 0;
}