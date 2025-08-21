#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edge_list; // this is edge list, where pair is the data type, in pair there are two integer data

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b}); // we put a, b in the vector as pair
    }

    for (pair<int, int> p : edge_list) // print pair
    {
        cout << p.first << " " << p.second << endl;
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
// 0 1
// 0 2
// 3 0
// 1 3
// 3 4