#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> adj_list[105];

bool visited[105];
bool pathVisited[105];
bool flag;

void dfs(int src)
{
    visited[src] = true;
    pathVisited[src] = true;
    for (int child : adj_list[src])
    {
        if (visited[child] == true && pathVisited[child] == true)
        {
            flag = true;
        }

        if (visited[child] == false)
        {
            dfs(child);
        }
    }

    // return
    pathVisited[src] = false;
}

int main()
{

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        // adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));

    flag = false;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
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
