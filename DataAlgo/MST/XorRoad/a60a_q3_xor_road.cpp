#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ull> road(n);
    vector<vector<pair<int, ull>>> graph(n);
    for (int i = 0; i < n; i++)
    {
        cin >> road[i];

        for (int j = i - 1; j >= 0; j--)
        {
            ull value = road[i] ^ road[j];

            graph[i].push_back({j, value});
            graph[j].push_back({i, value});
        }
    }

    priority_queue<pair<ull, int>> pq;
    vector<bool> visited(n, false);
    ull ans = 0;

    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [value, curr] = pq.top();
        pq.pop();

        if (visited[curr])
        {
            continue;
        }

        visited[curr] = true;
        ans += value;

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