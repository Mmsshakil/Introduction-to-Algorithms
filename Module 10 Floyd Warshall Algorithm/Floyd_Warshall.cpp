#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    // set infinity value and 0 in points
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    // take input from user and put value in the point
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
    }

    //  main kaj
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && (adj_mat[i][k] + adj_mat[k][j]) < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
                // cout << i << " " << k << " " << j << endl;
            }
        }
    }

    // print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << adj_mat[i][j] << " ";
            }
        }
        cout << endl;
    }

    // check is there any cycle or not
    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[i][i] < 0)
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "\nThere is a cycle" << endl;
    }
    else
    {
        cout << "\nThere isnt any cycle" << endl;
    }

    return 0;
}

// input:
// 4 5
// 0 1 3
// 0 2 6
// 1 2 2
// 1 3 5
// 2 3 4

// output:
// 0 3 5 8
// INF 0 2 5
// INF INF 0 4
// INF INF INF 0
