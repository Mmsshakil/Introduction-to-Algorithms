#include <bits/stdc++.h>
using namespace std;

long long INF = 1e15;

int main()
{
    int n, e;
    cin >> n >> e;

    long long adj_mat[105][105];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c); // handle multiple edges
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] < INF && adj_mat[k][j] < INF)
                {
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int src, des;
        cin >> src >> des;

        if (adj_mat[src][des] >= INF)
            cout << -1 << endl;
        else
            cout << adj_mat[src][des] << endl;
    }

    return 0;
}
