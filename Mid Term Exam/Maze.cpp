#include <bits/stdc++.h>
using namespace std;

// vector<int> adj_list[1005];

int row, col;

char grid[1005][1005];
bool visited[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) // here we will check valid or not
{
    if (i < 0 || i >= row || j < 0 || j >= col)
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

        // cout << par << " ";

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) == true && visited[ci][cj] == false && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                parent[ci][cj] = par;
                // parent[ci][cj] = {pi, pj};
            }
        }
    }
}

int main()
{

    cin >> row >> col;

    int si, sj, di, dj;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j; // start at R
            }
            else if (grid[i][j] == 'D')
            {
                di = i;
                dj = j; // destination is D
            }
        }
    }

    // cout << si << " " << sj << " " << di << " " << dj << endl;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent)); // parent ar sob gulake -1 kore dibo

    bfs(si, sj);

    // cout << visited[di][dj] << endl;

    if (visited[di][dj])
    {
        // path print code start here
        int nod_i = di, nod_j = dj;

        while (!(nod_i == si && nod_j == sj))
        {
            pair<int, int> par = parent[nod_i][nod_j];
            nod_i = par.first;
            nod_j = par.second;

            if (nod_i == si && nod_j == sj)
            {
                break;
            }

            grid[nod_i][nod_j] = 'X';
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
