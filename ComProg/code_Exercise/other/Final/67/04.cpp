#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<pair<string, int>> correct;
    map<pair<string, int>, int> trying;
    map<string, int> penalty;
    map<string, int> count;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m, c;
        string t;
        char r;
        cin >> m >> t >> c >> r;
        auto x = make_pair(t, c);
        if (correct.count(x))
        {
            continue;
        }
        if (r == 'T')
        {
            penalty[t] += (20 * trying[x] + m);
            correct.insert(x);
            count[t]++;
        }
        else
        {
            trying[x]++;
        }
    }

    map<pair<int, int>, set<string>> result;
    for (auto [t, c] : correct)
    {
        result[make_pair(-count[t], penalty[t])].insert(t);
    }

    int rank = 0;
    for (auto [a, b] : result)
    {
        for (auto t : b)
        {
            cout << t << " " << -a.first << " " << a.second << "\n";
            rank++;
        }
        if (rank >= 3)
        {
            break;
        }
    }
}
