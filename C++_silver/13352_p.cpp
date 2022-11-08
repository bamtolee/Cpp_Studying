#include <iostream>
#include <vector>
using namespace std;

long long int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long long int a = (long long)x1 * (long long)y2 + (long long)x2 * (long long)y3 + (long long)x3 * (long long)y1;
	long long int b = (long long)y1 * (long long)x2 + (long long)y2 * (long long)x3 + (long long)y3 * (long long)x1;
	return a - b;
}

int main()
{
    int n, tx, ty, i;
    vector<int> x;
    vector<int> y;
    vector<int> line1_index;
    vector<int> line2_index;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tx >> ty;
        x.push_back(tx);
        y.push_back(ty);
    }
    if (n <= 4)
    {
        cout << "success";
        return 0;
    }
    for(i = 0; i < 3; i++)
    {
        int j = i + 1;
        for(; j < 4; j++)
        {
            int k = j + 1;
            for(; k < 5; k++)
            {
                if(ccw(x[i], y[i], x[j], y[j], x[k], y[k]) == 0)
                {
                    line1_index.push_back(i);
                    line1_index.push_back(j);
                    line1_index.push_back(k);
                    break;
                }
            }
            if (k != 5)
                break;
        }
        if (j != 4)
            break;
    }
    if(i == 3)
    {
        cout << "failure";
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        if(ccw(x[line1_index[0]], y[line1_index[0]], x[line1_index[1]], y[line1_index[1]], x[i], y[i]) == 0)
            continue;
        if(line2_index.size() < 2)
        {
            line2_index.push_back(i);
            continue;
        }
        else
        {
            if(ccw(x[line2_index[0]], y[line2_index[0]], x[line2_index[1]], y[line2_index[1]], x[i], y[i]) == 0)
                continue;
            else
            {
                cout << "failure";
                return 0;
            }
        }
    }
    cout << "success";
    return 0;
}