#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long row, col, n;
    cin >> row >> col >> n;

    vector<pair<int, int>> fav(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fav[i].first >> fav[i].second;
    }

    sort(fav.begin(), fav.end());

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;

        pair<int, int> tmp = {r, c};
        auto it = lower_bound(fav.begin(), fav.end(), tmp);

        int favR = it->first;
        int favC = it->second;

        if (it == fav.end())
        {
            favR = fav[0].first;
            favC = fav[0].second;
        }

        long long ans = favC - c;
        if (favR > r)
        {
            ans = col * (favR - r - 1) + (col - c) + favC;
        }
        else if ((favR <= r && favC < c) || favR < r)
        {
            ans = col * (row - r) + (col - c) + col * (favR - 1) + favC;
        }

        cout << ans << endl;
    }
}
