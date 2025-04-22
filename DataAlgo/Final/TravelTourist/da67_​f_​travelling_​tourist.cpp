#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    set<int> s;
    for (int i = 1; i <= k; i++)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    vector<vector<pair<int, int>>> graph(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n + 1, false);
    pq.push({0, *s.begin()});
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

        if (s.find(curr) != s.end())
        {
            s.erase(curr);
        }

        if (s.empty())
        {
            break;
        }

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
