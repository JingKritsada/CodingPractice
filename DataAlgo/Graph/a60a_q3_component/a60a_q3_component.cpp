#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[curr] = true;
    for (int next : graph[curr])
    {
        if (!visited[next])
        {
            dfs(next, graph, visited);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v + 1);
    vector<bool> visited(v + 1, false);

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}