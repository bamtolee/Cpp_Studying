#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int test_case;
	int T;
    int sdoku[9][9] = {0};
    int check[10] = {0};

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int flag = 1;

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                cin >> sdoku[i][j];
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                check[sdoku[i][j]]++;
                if(check[sdoku[i][j]] > 1)
                {   
                    flag = 0;
                    break;
                }
            }
            fill_n(check, 10, 0);
            if(flag == 0) break;
        }
        if(flag != 0)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    check[sdoku[j][i]]++;
                    if(check[sdoku[j][i]] > 1)
                    {   
                        flag = 0;
                        break;
                    }
                }
                fill_n(check, 10, 0);
                if(flag == 0) break;
            }
        }
        if(flag != 0)
        {
            int k = 0, l = 0;
            for(int a = 0; a < 9; a++)
            {
                for(int i = 0 + k; i < 3 + k; i++)
                {
                    for(int j = 0 + l; j < 3 + l; j++)
                    {
                        check[sdoku[i][j]]++;
                        if(check[sdoku[i][j]] > 1)
                        {   
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 0) break;
                }
                fill_n(check, 10, 0);
                if(flag == 0) break;
                l += 3;
                if(l >= 9)
                {
                    l = 0;
                    k += 3;
                }
            }
        }
        for(int i = 0; i < 9; i++)
            fill_n(sdoku[i], 9, 0);
        cout << "#" << test_case << " " << flag << "\n";
	}
	return 0;
}