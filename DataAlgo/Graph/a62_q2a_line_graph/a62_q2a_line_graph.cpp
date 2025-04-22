#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[curr] = true;

    for (int next : graph[curr])
    {
        if (graph[next].size() > 2)
        {
            return false;
        }

        if (!visited[next])
        {
            if (!dfs(next, graph, visited))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    vector<bool> visited(v, false);

    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int cnt = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (graph[i].size() <= 1 && dfs(i, graph, visited))
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}