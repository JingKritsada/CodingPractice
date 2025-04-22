#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int wei, a, b;
        cin >> wei >> a >> b;

        graph[a].push_back({b, wei});
        graph[b].push_back({a, wei});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n + 1, false);
    pq.push({0, 1});
    int ans = 0;

    while (!pq.empty())
    {
        auto [cost, curr] = pq.top();
        pq.pop();

        if (visited[curr])
        {
            continue;
        }

        visited[curr] = true;
        ans += cost;

        for (auto [next, wei] : graph[curr])
        {
            if (!visited[next])
            {
                pq.push({wei, next});
            }
        }
    }

    cout << ans;

    return 0;
}