#include <iostream>
#include <vector>
using namespace std;

void swap(vector <int> &v, int i, int j)
{
    int tmp;

    tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

int partition(vector<int> &v, int left, int right)
{
    int i = left, j = right, mid = (left + right) / 2;
    swap(v, left, mid);
    int pivot = v[left];

    while(i < j)
    {
        while(v[j] < pivot) j--;
        while(v[i] >= pivot && i < j) i++;
        swap(v, i, j);
    }
    v[left] = v[i];
    v[i] = pivot;
    return i;
}

void quick_sort_descending(vector<int> &v, int left, int right)
{
    if(left >= right) return;

    int pivot = partition(v, left, right);
    quick_sort_descending(v, left, pivot - 1);
    quick_sort_descending(v, pivot + 1, right);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> v;

    cin >> n;
    while(n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    quick_sort_descending(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++) cout << v[i]; // 내림차순으로 정렬한 경우
    //오름차순으로 정렬한 경우
    /*while(v.size())
    {
        cout << v.back();
        v.pop_back();
    }*/
    return 0;
}