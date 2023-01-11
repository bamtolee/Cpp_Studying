#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int test_case;
	int T;
	
	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int **arr;

        cin >> n;
        arr = new int*[n];

        for(int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        }

        cout << "#" << test_case << "\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
                cout << arr[j][i];
            cout << " ";
            for(int k = n - 1; k >= 0; k--)
                cout << arr[n - 1 - i][k];
            cout << " ";
            for(int l = 0; l < n; l++)
                cout << arr[l][n - 1 - i];
            cout << "\n";   
        }

        for(int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
	}
	return 0;
}