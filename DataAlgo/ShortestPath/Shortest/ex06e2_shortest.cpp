#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int from, to, wei;
};

int main()
{
    int N, E, s;
    cin >> N >> E >> s;

    vector<edge> graph(E);
    for (int i = 0; i < E; i++)
    {
        cin >> graph[i].from >> graph[i].to >> graph[i].wei;
    }

    vector<int> dist(N, INT_MAX / 2);
    bool chk = false;
    dist[s] = 0;

    for (int i = 0; i < N; i++)
    {
        chk = false;
        for (auto &x : graph)
        {
            if (dist[x.from] + x.wei < dist[x.to])
            {
                dist[x.to] = dist[x.from] + x.wei;
                chk = true;
            }
        }
    }

    if (chk)
    {
        cout << -1;
    }
    else
    {
        for (int &x : dist)
        {
            cout << x << " ";
        }
    }

    return 0;
}