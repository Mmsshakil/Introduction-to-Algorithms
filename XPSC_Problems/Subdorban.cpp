#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool visited[1005][1005];
int level[105][105];

vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n;

bool valid(int i, int j) // here we will check valid or not
{
    if (i < 0 || i >= n || j < 0 || j >= n)
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
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        // cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mov[i].first;
            int cj = par_j + mov[i].second;

            if ((valid(ci, cj) == true) && (!visited[ci][cj]) && (grid[ci][cj] != 'T'))
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{

    while (cin >> n)
    {

        int si, sj, di, dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if (grid[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        bfs(si, sj);

        cout << level[di][dj] << endl;

        // cout << si << " " << sj << endl;
        // cout << di << " " << dj << endl;
    }

    return 0;
}

// input:
// 3 4
// ....
// .#..
// .#..
// 1 2
// 2 0

// output: 5
