#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, e, q;
    cin >> n >> e >> q;
    long long int adj_mat[n + 5][n + 5];

    // set infinity value and 0 in points
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    // take input from user and put value in the point
    for (int i = 1; i <= e; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;

        if (adj_mat[a][b] > c)
        {
            adj_mat[a][b] = c;
            adj_mat[b][a] = c; // undirected graph
        }
    }

    //  main kaj
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && (adj_mat[i][k] + adj_mat[k][j]) < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
                // cout << i << " " << k << " " << j << endl;
            }
        }
    }

    for (int k = 1; k <= q; k++)
    {
        long long int i, j;
        cin >> i >> j;
        if (adj_mat[i][j] == LLONG_MAX)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << adj_mat[i][j] << endl;
        }
    }

    return 0;
}

// input:
// 4 3 5
// 1 2 5
// 1 3 9
// 2 3 3
// 1 2
// 2 1
// 1 3
// 1 4
// 3 2

// output:
// 5
// 5
// 8
// -1
// 3
