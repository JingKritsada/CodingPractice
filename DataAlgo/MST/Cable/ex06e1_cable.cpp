#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cost;
            cin >> cost;

            graph[i].push_back({j, cost});
            graph[j].push_back({i, cost});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    int ans = 0;

    pq.push({0, 0});
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

        for (auto &[next, wei] : graph[curr])
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