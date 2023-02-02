#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, **paper, max = 0, tmp;

    cin >> n >> m;
    paper = new int*[n];
    for(int i = 0; i < n; i++)
        paper[i] = new int[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> paper[i][j];
    // #1 [][][][]
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 3; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
            if(tmp > max) max = tmp;
        }
    }
    // #1 rotation
    for(int i = 0; i < n - 3; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
            if(tmp > max) max = tmp;
        }
    }
    // #2 [][]
    //    [][]
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 1 [][][]
    //        []
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 2 []
    //        []
    //        [][]
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 3     []
    //        [][][]
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 4 [][]
    //          []
    //          []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 5 [][][]
    //            []
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j + 2] + paper[i][j + 1] + paper[i][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 6   []
    //          []
    //        [][]
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i + 2][j] + paper[i + 2][j + 1] + paper[i + 1][j + 1] + paper[i][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 7 []
    //        [][][]
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #3 - 4 [][]
    //        []
    //        []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j];
            if(tmp > max) max = tmp;
        }
    }
    // #4 - 1 []
    //        [][]
    //          []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #4 - 2   [][]
    //        [][]
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i - 1][j + 1] + paper[i - 1][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #4 - 3   []
    //        [][]
    //        []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j];
            if(tmp > max) max = tmp;
        }
    }
    // #4 - 4 [][]
    //          [][]
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #5 - 1 [][][]
    //          []
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2];
            if(tmp > max) max = tmp;
        }
    }
    // #5 - 2 []
    //        [][]
    //        []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j];
            if(tmp > max) max = tmp;
        }
    }
    // #5 - 3   []
    //        [][][]
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            tmp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 1];
            if(tmp > max) max = tmp;
        }
    }
    // #5 - 4   []
    //        [][]
    //          []
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            tmp = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i + 2][j + 1];
            if(tmp > max) max = tmp;
        }
    }

    cout << max;
    return 0;
}