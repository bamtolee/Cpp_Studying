#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string find_non_zero(string a)
{
    int index = 0;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '0')
		{
			index = i;
			break;
		}
	}
	if (index == a.length())
		return "0";
	return a.substr(index);
}

string toobig_add(string a, string b)
{
    long long mid = 0;
    string ret;

    for(int i = 0; i < a.length() || i < b.length(); i++)
    {
        if(i < a.length()) mid += a[a.length() - i - 1] - '0';
        if(i < b.length()) mid += b[b.length() - i - 1] - '0';
        ret += (mid % 10) + '0';
        mid /= 10;
    }
    if(mid >= 1) ret += mid + '0';
    reverse(ret.begin(), ret.end());
    return find_non_zero(ret);
}


int main()
{
    int n;
    string tmp;
    vector<string> v;

    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        if(i == 0) tmp = "0";
        else if(i == 1) tmp = "1";
        else tmp = toobig_add(v[i - 2], v[i - 1]);
        v.push_back(tmp);
    }
    cout << v.back();
    return 0;
}