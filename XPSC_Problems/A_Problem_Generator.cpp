#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        // frequency array
        int fre[7] = {0};
        for (auto c : s)
        {
            fre[c - 'A']++;
        }
        // ////////////////////

        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (fre[i] < m)
            {
                count = count + (m - fre[i]);
            }
        }

        cout << count << endl;
    }

    return 0;
}