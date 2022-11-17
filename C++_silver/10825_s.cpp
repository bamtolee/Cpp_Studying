#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct student{
    string name;
    int korean;
    int math;
    int english;
};

bool compare(student a, student b)
{
    if(a.english == b.english && a.korean == b.korean && a.math == b.math) return a.name < b.name;
    else if(a.english == b.english && a.korean == b.korean) return a.math > b.math;
    else if(a.korean == b.korean) return a.english < b.english;
    else return a.korean > b.korean;
}

int main()
{
    int n;
    student mem;
    vector<student> v;

    cin >> n;
    while(n--)
    {
        cin >> mem.name >> mem.korean >> mem.english >> mem.math;
        v.push_back(mem);
    }
    sort(v.begin(), v.end(), compare);
    for(auto i : v) cout << i.name << "\n";
    return 0;
}