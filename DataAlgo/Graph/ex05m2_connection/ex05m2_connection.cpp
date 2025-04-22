#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, int cnt, int k, vector<vector<int>> &graph, set<int> &friends, vector<bool> &visited)
{
    friends.insert(curr);
    visited[curr] = true;

    for (int next : graph[curr])
    {
        if (!visited[next] && cnt < k)
        {
            // printf("curr : %d, next : %d, cnt : %d\n", curr, next, cnt);
            dfs(next, cnt + 1, k, graph, friends, visited);
        }
    }

    visited[curr] = false;
}

int main()
{
    int v, e, k;
    cin >> v >> e >> k;

    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int mx = 0;
    for (int i = 0; i < v; i++)
    {
        set<int> friends;
        vector<bool> visited(v, false);

        dfs(i, 0, k, graph, friends, visited);
        // cout << "\n";

        if (friends.size() > mx)
        {
            mx = friends.size();
        }
    }

    cout << mx;

    return 0;
}