#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool visited[1005][1005];
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) // here we will check valid or not
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + mov[i].first;
        cj = sj + mov[i].second;

        if ((valid(ci, cj) == true) && (visited[ci][cj] == false))
        {
            dfs(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(visited, false, sizeof(visited));

    int si, sj;
    cin >> si >> sj;

    dfs(si, sj);

    return 0;
}

// input:
// 3 4
// ....
// ....
// ....
// 1 2

// output:
// 1 2
// 0 2
// 0 1
// 1 1
// 2 1
// 2 0
// 1 0
// 0 0
// 2 2
// 2 3
// 1 3
// 0 3

// complexity: O(row X column)