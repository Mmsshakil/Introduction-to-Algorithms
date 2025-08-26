#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    for (auto idx : mov)
    {
        int ci = si + idx.first;
        int cj = sj + idx.second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] != '#')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}