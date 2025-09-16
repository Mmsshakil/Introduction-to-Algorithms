#include <bits/stdc++.h>
using namespace std;

int val[1005];
int weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0) // i ar value < 0 / max weight <= 0 , hoile recursion stop hoya jabe
    {
        return 0;
    }

    if (dp[i][mx_weight] != -1)
    {
        return dp[i][mx_weight];
    }

    if (weight[i] <= mx_weight)
    {
        // have two options
        // 1. bag a rakhbo 2. bag a rakhte parbo na
        int op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        // have only on option
        // 1. bag a rakhte parbona
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = op2;
        return dp[i][mx_weight];
    }
}

int main()
{

    int n, mx_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cin >> mx_weight;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mx_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, mx_weight) << endl;

    return 0;
}

// input:
// 4
// 10 4 7 5
// 4 3 2 5
// 8

// output:
// 17

// complexity: O(NW)