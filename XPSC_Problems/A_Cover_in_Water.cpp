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
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
            {
                flag = true;
                break;
            }
            else if (s[i] == '.')
            {
                count++;
            }
        }

        if (flag)
        {
            cout << "2" << endl;
        }
        else
        {
            cout << count << endl;
        }
    }

    return 0;
}