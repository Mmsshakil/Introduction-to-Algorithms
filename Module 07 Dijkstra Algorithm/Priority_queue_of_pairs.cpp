#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({5, 3});
    pq.push({10, 7});
    pq.push({2, 1});

    cout << pq.top().first << " " << pq.top().second << endl;
    return 0;
}