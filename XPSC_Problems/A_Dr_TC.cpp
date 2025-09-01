#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
        }

        int final = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                final = final + count - 1;
            }
            else if (s[i] == '0')
            {
                final = final + count + 1;
            }
        }

        cout << final << endl;
    }

    return 0;
}