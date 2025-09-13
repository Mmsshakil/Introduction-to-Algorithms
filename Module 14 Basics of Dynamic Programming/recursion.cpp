#include <bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if (n > 5)
    {
        return 0;
    }
    int total = rec(n + 1);
    return total + 1;
}

int main()
{
    cout << rec(1) << endl;

    return 0;
}