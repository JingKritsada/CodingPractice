/*
#include <bits/stdc++.h>
using namespace std;

bool findcycle(int curr, int prev, vector<vector<int>> &edges, vector<bool> &visited)
{
    visited[curr] = true;
    for (auto &next : edges[curr])
    {
        if (visited[next] && next != prev)
        {
            return true;
        }
        else if(!visited[next])
        {
            if (findcycle(next, curr, edges, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> edges(v);
        vector<bool> visited(v, false);

        for (int j = 0; j < e; j++)
        {
            int v1, v2;
            cin >> v1 >> v2;

            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }

        bool chk = false;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j])
            {
                if (findcycle(j, -1, edges, visited))
                {
                    chk = true;
                    break;
                }
            }
        }

        if (chk)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int prev, int curr, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[curr] = true;

    for (int next : graph[curr])
    {
        if (next != prev && visited[next])
        {
            return true;
        }
        else if (!visited[next])
        {
            if (dfs(curr, next, graph, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
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

        bool chk = false;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(-1, i, graph, visited))
                {
                    chk = true;
                }
            }
        }

        if (chk)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}