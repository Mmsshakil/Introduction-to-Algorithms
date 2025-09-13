#include <bits/stdc++.h>
using namespace std;

int facto(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int mul = facto(n - 1);
    return mul * n;
}

int main()
{
    cout << facto(5) << endl;
    return 0;
}