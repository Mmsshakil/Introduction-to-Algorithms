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

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mov[i].first;
            int cj = par_j + mov[i].second;

            if ((valid(ci, cj) == true) && (!visited[ci][cj]))
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
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

    bfs(si, sj);

    return 0;
}
