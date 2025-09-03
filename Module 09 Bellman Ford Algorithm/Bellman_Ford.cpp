#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // if the graph is undirected
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    // main kaj
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] + c < dis[b] && dis[a] != INT_MAX)
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    //  cycle detect extra code/////////////////////////

    bool cycle = false;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] + c < dis[b] && dis[a] != INT_MAX)
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
    {
        cout << "Negative Weighted Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    // //////////////////////////////////////////////////

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

// input:
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// output:
// 0 -> 0
// 1 -> 7
// 2 -> 5
// 3 -> 10

// complexity: O(VE)
