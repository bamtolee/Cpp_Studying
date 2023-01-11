#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    vector<int> v(101);

	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int tc;
        int tmp, max = 0, ret = 0;

        cin >> tc;
        for(int i = 0; i < 1000; i++)
        {
            cin >> tmp;
            v[tmp]++;
        }
        for(int i = 0; i < 101; i++)
        {
            if(v[i] >= max)
            {
                max = v[i];
                ret = i;
            }
        }
        fill(v.begin(), v.end(), 0);
        cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}