#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[1005];
int distanc[1005]; // source/0 thake kon node ar distance koto sgolo thakbe

void dijkstra(int src)
{
    queue<pair<int, int>> q; // take a queue
    q.push({src, 0});        // first set the source on queue
    distanc[src] = 0;        // source ar distance ta 0 kore dilam nijer hate

    while (!q.empty())
    {
        // 1. ber kore ana
        pair<int, int> par = q.front();
        q.pop();

        int parnt_node = par.first;
        int parnt_distanc = par.second;

        // 2. oi node ke niye kaj
        // aikhane asole oi node niya kono kaj nai taile kisu a nai

        // 3. children gulo push kora
        for (pair<int, int> child : adj_list[parnt_node])
        {

            int child_node = child.first;
            int child_distanc = child.second;

            if (parnt_distanc + child_distanc < distanc[child_node]) // aikhane check korbo path relaxation kora jay kina
            {
                distanc[child_node] = parnt_distanc + child_distanc; // distance ta update korbo
                q.push({child_node, distanc[child_node]});           //  path ta queue a push korbo
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    // memset(distanc, INT_MAX, sizeof(distanc)); // ata kisu somoy somossa kore tai forloop use korbo
    for (int i = 0; i < n; i++)
    {
        distanc[i] = INT_MAX;
    }

    dijkstra(0); // here we call the diakstra function for 0 source

    // print min distance of every node from 0
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << distanc[i] << endl;
    }

    return 0;
}

// input:
// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5

// output:
// 0->0
// 1->6
// 2->5
// 3->4
// 4->9

// complexity : O(V*E)
