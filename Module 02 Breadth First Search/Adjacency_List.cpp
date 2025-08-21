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

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int x : adj_list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// input:
// 5 5
// 0 1
// 0 2
// 3 0
// 1 3
// 3 4

// output: 
// 0 : 1 2 3 
// 1 : 0 3 
// 2 : 0 
// 3 : 0 1 4 
// 4 : 3 
