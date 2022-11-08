#include <iostream>
#include <vector>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}

int main()
{
    int tx, ty, jud, ret;
    vector<int> x;
    vector<int> y;

    for(int i = 0; i < 3; i++)
    {
        cin >> tx >> ty;
        x.push_back(tx);
        y.push_back(ty);
    }
    jud = ccw(x[0], y[0], x[1], y[1], x[2], y[2]);
    if (jud == 0) ret = 0;
    else if (jud < 0) ret = -1;
    else if (jud > 0) ret = 1;
    cout << ret;
    return 0;
}