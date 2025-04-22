#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int dis;
            cin >> dis;
            if (dis > 0)
            {
                graph[i].push_back({j, dis});
            }
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [currDist, currNode] = pq.top();
        pq.pop();

        if (currDist > dist[currNode])
        {
            continue;
        }

        for (auto &[nextNode, wei] : graph[currNode])
        {
            int newDist = currDist + wei;
            if (newDist < dist[nextNode])
            {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    int ans = 0;
    for (int &x : dist)
    {
        if (x > ans)
        {
            ans = x;
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    return 0;
}
