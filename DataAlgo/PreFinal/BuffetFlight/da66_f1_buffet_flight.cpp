/*
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int from, to, wei;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ci(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ci[i];
    }

    vector<int> co(n);
    for (int i = 0; i < n; i++)
    {
        cin >> co[i];
    }

    vector<edge> graph;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        graph.push_back({from, to, co[from] + ci[to]});
    }

    vector<int> cost(n, INT_MAX / 2);
    cost[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &x : graph)
        {
            if (cost[x.from] + x.wei < cost[x.to])
            {
                cost[x.to] = cost[x.from] + x.wei;
            }
        }
    }

    for (auto &x : cost)
    {
        if (x == INT_MAX / 2)
        {
            cout << "-1 ";
        }
        else
        {
            cout << x << " ";
        }
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ci(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ci[i];
    }

    vector<int> co(n);
    for (int i = 0; i < n; i++)
    {
        cin >> co[i];
    }

    vector<vector<int>> graph(n);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    vector<int> cost(n, INT_MAX);
    cost[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [currCost, currNode] = pq.top();
        pq.pop();

        if (currCost > cost[currNode])
        {
            continue;
        }

        for (auto &next : graph[currNode])
        {
            int newCost = currCost + co[currNode] + ci[next];

            if (newCost < cost[next])
            {
                cost[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }

    for (int &x : cost)
    {
        if (x == INT_MAX)
        {
            cout << -1 << " ";
            continue;
        }

        cout << x << " ";
    }

    return 0;
}