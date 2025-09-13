#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fibo(n - 1) + fibo(n - 2);
        return dp[n];
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << fibo(6) << endl;
    return 0;
}