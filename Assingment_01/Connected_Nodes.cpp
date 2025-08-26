#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; // n - node; e - edge
    cin >> n >> e;

    vector<int> adj_list[n]; // array of vector where the size of the array is n; adj_list is an array and data type is vector

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected tai a thake b & b thake a te jaowa lagbe
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> print;
        int n;
        cin >> n;
        for (int x : adj_list[n])
        {
            print.push_back(x);
        }

        if (print.empty())
        {
            cout << "-1" << endl;
        }
        else
        {

            sort(print.begin(), print.end(), greater<int>());

            for (int y : print)
            {
                cout << y << " ";
            }

            cout << endl;
        }
    }

    return 0;
}
