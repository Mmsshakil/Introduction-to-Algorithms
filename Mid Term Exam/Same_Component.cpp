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

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

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
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    memset(visited, false, sizeof(visited));

    bfs(si, sj);

    cout << (visited[di][dj] ? "YES" : "NO") << endl;
    return 0;
}
