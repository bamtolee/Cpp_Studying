#include <iostream>
using namespace std;

void swap(int a[], int i, int j)
{
    int tmp;

    tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}

int partition(int a[], int left, int right)
{
    int i = left, j = right, mid = (left + right) / 2;
    swap(a, left, mid);
    int pivot = a[left];

    while(i < j)
    {
        while(a[j] > pivot) j--;
        while(a[i] <= pivot && i < j) i++;
        swap(a, i, j);
    }
    a[left] = a[i];
    a[i] = pivot;
    return i;
}

void quick_sort(int a[], int left, int right)
{
    if(left >= right) return;

    int pivot = partition(a, left, right);
    quick_sort(a, left, pivot - 1);
    quick_sort(a, pivot + 1, right);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, tmp;
    int *a;

    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp;
    }
    quick_sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << "\n";
    delete[] a;
    return 0;
}