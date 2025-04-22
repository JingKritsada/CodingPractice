#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    unordered_map<string, int> score;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        if (score.find(name) == score.end())
        {
            score[name] = 0;
        }
        score[name]++;
    }

    priority_queue<pair<int, string>> sorted;
    for (auto x : score)
    {
        sorted.push({x.second, x.first});
    }

    int ans;
    while (!sorted.empty() && k > 0 && sorted.top().first > 0)
    {
        ans = sorted.top().first;
        sorted.pop();
        k--;
    }

    cout << ans;

    return 0;
}