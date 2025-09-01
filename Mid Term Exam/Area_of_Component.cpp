#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];

int n, m;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
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

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    int area = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                area++;
            }
        }
    }
    return area;
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

    int minArea = INT_MAX;
    bool hasComponent = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int area = bfs(i, j);
                minArea = min(minArea, area);
                hasComponent = true;
            }
        }
    }

    if (hasComponent)
    {
        cout << minArea << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}
