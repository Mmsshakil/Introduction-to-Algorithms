#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> adj_list[105];

bool visited[105];
int parent[105];
bool flag;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (visited[child] == true && parent[par] != child)
            {
                flag = true;
            }

            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main()
{

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    flag = false;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            bfs(i);
        }
    }

    if (flag == true)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }

    return 0;
}

// input:
// 6 5
// 0 1
// 1 2
// 2 3
// 3 0
// 4 5

// output: Cycle Detected
