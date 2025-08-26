#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj, int &cnt)
{
    cnt++;
    vis[si][sj] = true;
    for (auto idx : d)
    {
        int ci = si + idx.first;
        int cj = sj + idx.second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj, cnt);
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
    memset(vis, false, sizeof(vis));
    list<int> rooms;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (!vis[i][j] && grid[i][j] != '#')
            {
                dfs(i, j, cnt);
                if (cnt != 0)
                {
                    rooms.push_back(cnt);
                }
            }
        }
    }
    if (rooms.empty())
    {
        cout << 0;
    }
    else
    {
        rooms.sort();
        for (int x : rooms)
        {
            cout << x << ' ';
        }
    }
    return 0;
}