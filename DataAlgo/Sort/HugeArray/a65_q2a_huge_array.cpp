#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    map<int, int> sequence;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        sequence[x] += c;
    }

    set<pair<int, int>> s;
    int qsum = 0;

    for (auto &x : sequence)
    {
        qsum += x.second;
        s.insert({qsum, x.first});
    }

    for (int i = 0; i < q; i++)
    {
        int tar;
        cin >> tar;

        auto pos = s.lower_bound({tar, 0});
        cout << (*pos).second << "\n";
    }

    return 0;
}

// 1 10 5 1 3
// 1 1 3 5 10

// 9 4 4 4 4 4 9 9 9 8 8 8 7 7 7 7 7 7 7
// 4 4 4 4 4 7 7 7 7 7 7 7 8 8 8 9 9 9 9
// 5 7 8 4
// 5 12 20 24