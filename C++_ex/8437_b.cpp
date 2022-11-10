#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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

string toobig_div_to2(string str)
{
    long long mid = 0;
    string ret;
    bool flag = false;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '-')
        {
            flag = true;
            continue;
        }
        mid = (mid * 10) + str[i] - '0';
        ret += (mid/2) + '0';
        mid %= 2;
    }
    ret = find_non_zero(ret);
    if(flag) ret.insert(0, "-");
    return ret;
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

bool toobig_sub_check(string &a, string &b)
{
    if(a.length() > b.length()) return false;
    else if(a.length() < b.length())
    {
        swap(a, b);
        return true;
    }
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] > b[i]) return false;
        else if(a[i] < b[i])
        {
            swap(a, b);
            return true;
        }
    }
    return false;
}

string toobig_sub(string a, string b)
{
    bool carry = false;
    bool minus_flag = toobig_sub_check(a, b);
    long long mid = 0;
    string ret;

    for(int i = 0; i < a.length() || i < b.length(); i++)
    {
        if(i < a.length())
        {
            mid += a[a.length() - i - 1] - '0';
            if(carry)
            {
                mid--;
                carry = false;
            }
        }
        if(i < b.length())
        {
            mid -= b[b.length() - i - 1] - '0';
        }
        if(mid < 0)
        {
            mid = 10 - abs(mid);
            carry = true;
        }
        ret += mid + '0';
        mid = 0;
    }
    reverse(ret.begin(), ret.end());
    ret = find_non_zero(ret);
    if(minus_flag) ret.insert(0, "-");
    return ret;
}

int main()
{
    string a, b, mid1, mid2;
    string ret1, ret2;

    cin >> a >> b;
    mid1 = toobig_add(a, b);
    mid2 = toobig_sub(a, b);
    ret1 = toobig_div_to2(mid1);
    ret2 = toobig_div_to2(mid2);
    cout << ret1 << "\n" << ret2;
    return 0;
}