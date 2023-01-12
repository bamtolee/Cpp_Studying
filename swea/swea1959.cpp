#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m, max_ret = INT_MIN;
        int *arr1, *arr2;

        cin >> n >> m;
        arr1 = new int[n];
        arr2 = new int[m];
        for(int i = 0; i < n; i++)
            cin >> arr1[i];
        for(int i = 0; i < m; i++)
            cin >> arr2[i];
        for(int i = 0; i <= max(n, m) - min(n, m); i++)
        {
            int tmp = 0, k = 0;
            for(int j = i; j < i + min(n, m); j++)
            {
                if(min(n, m) == n)
                    tmp += arr1[k] * arr2[j];
                else
                    tmp += arr1[j] * arr2[k];
                k++;
            }
            if(tmp >= max_ret) max_ret = tmp;
        }
        cout << "#" << test_case << " " << max_ret << "\n";
        delete[] arr1;
        delete[] arr2;
 	}
	return 0;
}