#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long int c;
    Edge(int a, int b, long long int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long int dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;

    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // if the graph is undirected
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dis[src] = 0;

    // main kaj
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] + c < dis[b] && dis[a] != LLONG_MAX)
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    //  cycle detect extra code/////////////////////////

    bool cycle = false;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] + c < dis[b] && dis[a] != LLONG_MAX)
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int des;
        cin >> des;
        if (dis[des] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[des] << endl;
        }
    }

    return 0;
}
