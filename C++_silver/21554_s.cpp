#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, *arr, count = 0;
    vector<pair<int, int>> v;

    cin >> n;
    arr = new int[n + 1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++)
    {
        if(i != arr[i])
        {
            int j = i;
            
            while(arr[j] != i && j <= n)
                j++;
            
            v.push_back(make_pair(i, j));
            count++;
            int d = j - i + 1;
            int *tmp_arr = new int[d];
            for(int k = 0; k < d; k++)
                tmp_arr[k] = arr[j--];

            int q = 0;
            for(int k = v[count - 1].first; k <= v[count - 1].second; k++)
                arr[k] = tmp_arr[q++];
        }
    }
    if(count > 100) cout << -1;
    else if(v.empty()) cout << 0;
    else
    {
        cout << count << "\n";
        for(auto e : v)
            cout << e.first << " " << e.second << "\n";
    }
    delete[] arr;
    return 0;
}