#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> line;
vector<int> p;
vector<line> l;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int a = x1 * y2 + x2 * y3 + x3 * y1;
    int b = x2 * y1 + x3 * y2 + x1 * y3;
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

int checkLineMeeting(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) == 0
    && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) == 0)
    {
        int min1 = x1 > x2 ? x2 : x1;
        int max1 = x1 < x2 ? x2 : x1;
        int max2 = x3 > x4 ? x3 : x4;
        int min2 = x4 < x3 ? x4 : x3;
        if(x1 == x2 && x2 == x3 && x3 == x4)
        {
            int miny1 = y1 > y2 ? y2 : y1;
            int maxy1 = y1 < y2 ? y2 : y1;
            int maxy2 = y3 > y4 ? y3 : y4;
            int miny2 = y4 < y3 ? y4 : y3;
            if(miny1 >= miny2 && maxy2 >= miny1)
                return 1;
            else if(miny2 >= miny1 && maxy1 >= miny2)
                return 1;
            else return 0;
        }
        else if(min1 >= min2 && max2 >= min1)
            return 1;
        else if(min2 >= min1 && max1 >= min2)
            return 1;
        else return 0;
    }
    else if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0
        && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) <= 0)
        return 1;
    else return 0;
}

void makeSet(int a)
{
    p[a] = a;
}

int findSet(int a)
{
    if(a == p[a]) return p[a];
    else return p[a] = findSet(p[a]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if(a != b)
    {
        if(a > b) p[a] = b;
        else p[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    p.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        l.push_back({{x1, y1}, {x2, y2}});
        makeSet(i);
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(checkLineMeeting(l[i].first.first, l[i].first.second, l[i].second.first, l[i].second.second,
                l[j].first.first, l[j].first.second, l[j].second.first, l[j].second.second) == 1)
                unionSet(i, j);
        }
    }

    map<int, int> m;
    int maxRet = 0;
    for(int i = 0; i < n; i++)
    {
        int curGroup = findSet(i);
        m[curGroup]++;
        if(m[curGroup] > maxRet) maxRet = m[curGroup];
    }
    cout << m.size() << "\n" << maxRet;
    return 0;
}