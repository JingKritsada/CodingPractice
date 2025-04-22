#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    vector<vector<pair<int, int>>> graph(n + 1);
    graph[1].push_back({2, c});
    graph[2].push_back({1, c});

    for (int i = 3; i <= n; i++)
    {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int t, p;
            cin >> t >> p;

            graph[i].push_back({t, p});
            graph[t].push_back({i, p});
        }

        vector<int> mnCost(n + 1, INT_MAX);
        mnCost[1] = 0;
        mnCost[2] = c;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto [currCost, currNode] = pq.top();
            pq.pop();

            if (currCost > mnCost[currNode])
            {
                continue;
            }

            for (auto [next, cost] : graph[currNode])
            {
                int newCost = mnCost[currNode] + cost;
                if (newCost < mnCost[next])
                {
                    mnCost[next] = newCost;
                    pq.push({newCost, next});
                }
            }
        }

        cout << mnCost[2] << " ";
    }

    return 0;
}