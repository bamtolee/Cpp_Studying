#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int test_case;
    int arr[100][100];
    int answer[102] = {0};
    int max, te;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        max = -2147483648;
        cin >> te;
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                cin >> arr[i][j];
        for(int i = 0; i < 100; i++)
        {
            int temp = 0;

            for(int j = 0; j < 100; j++)
            {
                temp += arr[i][j];
                if(j == i) 
                {
                    answer[100] += arr[i][j];
                    answer[j] += arr[i][j];
                }
                else if(j == 100 - i - 1) 
                {
                    answer[101] += arr[i][j];
                    answer[j] += arr[i][j];
                }
                else answer[j] += arr[i][j];
            }
            if (temp > max) max = temp;
        }
        for(int i = 0; i < 102; i++)
            if(answer[i] > max) max = answer[i];
        fill_n(answer, 102, 0);
        cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}