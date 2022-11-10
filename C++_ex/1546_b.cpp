#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, max = 0;
    vector<int> score;
    float ret = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        score.push_back(tmp);
    }
    for(auto i : score)
        if(i > max) max = i;
    for(auto i : score)
        ret += (float)i / float(max) * 100;
    ret /= n;
    cout << ret;
    return 0;
}