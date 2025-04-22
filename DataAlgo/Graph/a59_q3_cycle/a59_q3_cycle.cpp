#include <bits/stdc++.h>
using namespace std;

void dfs(int prev, int curr, int cnt, int &ans, vector<vector<int>> &graph, vector<int> &dis)
{
    dis[curr] = cnt;
    for (int next : graph[curr])
    {

        if (next != prev && ans == 0)
        {
            cout << cnt << ", curr : " << curr << ", next : " << next << "\n";

            if (dis[next] == 0)
            {
                dfs(curr, next, cnt + 1, ans, graph, dis);
            }
            else
            {
                ans = cnt - dis[next] + 1;
                return;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> dis(n, 0);

    while (n--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int ans = 0;
    dfs(-1, 0, 0, ans, graph, dis);

    cout << ans;

    return 0;
}