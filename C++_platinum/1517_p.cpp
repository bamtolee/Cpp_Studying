#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
vector<int> v;
ll ret;

void merge(int start, int mid, int end)
{
    vector<int> sorted;
    int left = start, right = mid + 1;
    while(left <= mid && right <= end)
    {
        if(v[right] >= v[left])
        {
            sorted.push_back(v[left]);
            left++;
        }
        else
        {
            sorted.push_back(v[right]);
            ret += mid - left + 1;
            right++;
        }
    }
    
    while(left <= mid)
    {
        sorted.push_back(v[left]);
        left++;
    }
    while(right <= end)
    {
        sorted.push_back(v[right]);
        right++;
    }

    for(int i = start; i <= end; i++)
        v[i] = sorted[i - start];
}

void mergeSort(int start, int end)
{
    if(start == end) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    mergeSort(0, n - 1);
    cout << ret;
    return 0;
}