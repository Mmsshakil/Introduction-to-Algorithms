#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e; // n- koto by koto ar matrix hbe n*n
    // e- total koto ta task asa ba kotota value add korte hbe graph a

    int adj_mat[n][n];

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         adj_mat[i][j] = 0;
    //     }
    // }

    memset(adj_mat, 0, sizeof(adj_mat)); // this will make all value of matrix is zero

    for (int i = 0; i < n; i++) // 1 thake 1 a j jaowa jay ba 2 thake 2, aijonno adj[1][1] = 1 kore dibo baki sob gulo o
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1; // matrix ar a num column b row ar value 1 kore dibo
        adj_mat[b][a] = 1; // matrix ar b num column a row ar value 1 kore dibo
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//  underected mane holo 1 thake 2 te jodi jaowa jay tahole , 2 thake o 1 a asa jabe

// input:
// 5 5
// 0 1
// 0 2
// 3 0
// 1 3
// 3 4

// output:
// 0 1 1 1 0
// 1 0 0 1 0
// 1 0 0 0 0
// 1 1 0 0 1
// 0 0 0 1 0