#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

bool checkDirectEdge(int src, int dst)
{
    if (src == dst)
    {
        return true;
    }

    for (int node : adj_list[src])
    {
        if (node == dst)
            return true;
    }
    return false;
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
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int src, dst;
        cin >> src >> dst;

        if (checkDirectEdge(src, dst))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
