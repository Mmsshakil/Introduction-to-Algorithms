#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005]; // 2. we made a visited array for check visited or not

void dfs(int src)
{
    cout << src << " "; // source ta print korbo
    visited[src] = true; // print ar sathe sathe oitak visited tru kore dibo
    for (int child : adj_list[src]) 
    {
        if (visited[child] == false) // check visited or not
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) // 1. we take the input here
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited)); // 3. we made all false of the visited array

    dfs(0);

    return 0;
}


// input: 
// 7 7
// 0 2
// 2 4
// 0 1
// 1 5
// 1 3
// 0 3
// 3 6

// output: 0 2 4 1 5 3 6 