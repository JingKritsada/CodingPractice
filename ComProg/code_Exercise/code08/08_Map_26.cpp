#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, set<string>> mp;
    string start, line;

    while (getline(cin, line))
    {
        string station1 = "", station2 = "";
        stringstream ss(line);
        ss >> station1 >> station2;

        if (station2 == "")
        {
            start = station1;
            break;
        }

        mp[station1].insert(station2);
        mp[station2].insert(station1);
    }

    set<string> ans;
    queue<pair<string, int>> q;
    unordered_map<string, bool> visited;

    ans.insert(start);
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        string curr = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (dis >= 2)
        {
            continue;
        }

        for (auto &x : mp[curr])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                ans.insert(x);
                q.push({x, dis + 1});
            }
        }
    }

    for (auto &x : ans)
    {
        cout << x << "\n";
    }

    return 0;
}