#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            pq.push({val, i});
        }

        int indx1 = pq.top().second;
        pq.pop();
        int indx2 = pq.top().second;

        cout << min(indx1, indx2) << " " << max(indx1, indx2) << endl;
    }

    return 0;
}