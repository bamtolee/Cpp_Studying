#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct member{
    int age;
    string name;
};

bool compare(member a, member b)
{
    return a.age < b.age;
}

int main()
{
    int n;
    member a;
    vector<member> v;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a.age >> a.name;
        v.push_back(a);
    }
    stable_sort(v.begin(), v.end(), compare);
    for(auto i : v)
        cout << i.age << " " << i.name << "\n";
    return 0;
}