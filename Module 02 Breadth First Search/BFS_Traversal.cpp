#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; // we will use adjacent list
bool visited[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        // 1. queue thake ber kore niya asa & queue ar top delete kora
        int par = q.front();
        q.pop();

        // 2. print kora
        cout << par << " ";

        // 3. jeta ber korsi tar child guloke push kora
        for (int child : adj_list[par])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
        }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited)); // we make the visited array fully false

    bfs(0);

    return 0;
}


// input: 
// 7 7
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5

// output: 0 1 3 4 2 5 6 
